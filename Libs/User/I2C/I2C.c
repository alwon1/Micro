//IIC0 Library Files
//Processor:  MC9S12XDP512
//Crystal:  16 MHz
//by P Ross Taylor
//December 2019

#include <hidef.h>
#include "derivative.h"
#include "I2C.h"

void IIC0_Init(void)
{
  IIC0_IBCR&=0b01111111;  //kill the bus if doing a reset
  
  DDRJ|=0b10000000;       //manually access SCL
  
  __asm("LDX #20;            //twenty times 5 us is enough to clock out 10 bits");
  __asm("BigLoop:");
    __asm("LDAA #10;");
    __asm("DBNE A,*;         //5 us in a toggle for 100kHz clk");
    PTJ^=0b10000000;      //toggle SCL
  __asm("DBNE X,BigLoop;");

  DDRJ&=0b01111111;       //free up SCL

  IIC0_IBFD=0x47;	  //100 kHz, SDA Hold = 20 cks, SCL Hold Start = 32 SCL Hold Stop = 42
  IIC0_IBCR|=0b10000000;  //enable the bus - must be done first
  IIC0_IBCR&=0b10111110;  //no interrupts, normal WAI
}


/************The following are genericized routines that can be used************/
/************for any device, given the timing diagrams provided*****************/
/************Borrowed heavily from Simon Walker, with some variations***********/

int IIC0_WaitForBus(void)           //function prevents lockup if bus isn't available
{                                   //returns FFFF after 10000 tries if not successful
  int iSpinCount = 0;
  
  while (++iSpinCount < 10000)
    if (!(IIC0_IBSR_IBB))           //IBB must be zero (bus free)
      return 0; 
  
  return -1;
}


//This routine expects the advertized IIC address, not left justified!!!!
int IIC0_Addr(char Address, char Read, char Restart, char WaitForBus) //don't wait for bus after Restart
{
    if (WaitForBus)
    {      
      if (IIC0_WaitForBus()) return -1;   //bus is busy -- deal with it in main.c
    }
    if(Restart)IIC0_IBCR_RSTA = 1;        //got bus -- restart if desired
    else IIC0_IBCR |= 0b00110000;         // master mode, transmitting (start)    

    if (!Read)
      IIC0_IBDR = Address*2 & 0b11111110; //send slave address w/write
    else
      IIC0_IBDR = Address*2 | 0x00000001; //send slave address w/read
      
    while (!IIC0_IBSR_IBIF);              //wait for completion

    IIC0_IBSR_IBIF = 1;                   //clear interrupt/flag
    
    
    if (!(IIC0_IBSR_RXAK)) return 0;      //all devices ack on the address announcement
    else IIC0_IBCR &=0b11001111;          //not master, not transmitting = stop 
    return -1;                            //likely no device at that address to respond
}  


int IIC0_WriteByte(char Val, char Stop)
{
  int iSpinCount = 0;

  IIC0_IBDR = Val;                
  
  // wait for interrupt flag w/bail on timeout
  while ((!(IIC0_IBSR_IBIF)) && (++iSpinCount < 10000));
  if (iSpinCount >= 10000) return -1;
  
  // no timeout, got flag, issue stop and clear flag (must be in this order)
  if (Stop) IIC0_IBCR&=0b11001111;            //not master, not transmitting = stop                   
  
  IIC0_IBSR_IBIF = 1;           
  
  // no error
  return 0;
}


int IIC0_ReadByte(char *buff, char Ack, char Stop)
//requires an 8-bit buffer in the main program; Restart for devices with calls to internal registers
//this function follows an address call and maybe a register call
{
  char Junk;    //needed for first fake-read of register
  
  if(Ack) IIC0_IBCR_TXAK = 0;  //on
  else IIC0_IBCR_TXAK = 1;     //off
  
  IIC0_IBCR &= 0b11101111;    //enable receive
  
  Junk = IIC0_IBDR;           //fake read
  
  while(!(IIC0_IBSR_IBIF));   //wait for operation complete flag
  
  if(Stop) IIC0_IBCR_MS_SL = 0;
  
  IIC0_IBSR_IBIF = 1;         //clear flag first
  *buff = IIC0_IBDR;          //real read
  
  return 0;                   //success
}