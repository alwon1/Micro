//IIC Library Components
//Processor:  MC9S12XDP512
//Crystal:  16 MHz
//by P Ross Taylor
//December 2019

/************The following are genericized routines that can be used************/
/************for any device, given the timing diagrams provided*****************/
/************Borrowed heavily from Simon Walker, with some variations***********/

/* if using Visual Studio Code or other context-sensitive editor, use these:*/

#define IIC0_STOP 1
#define IIC0_NOSTOP 0
#define IIC0_WRITE 0  
#define IIC0_READ 1
#define IIC0_ACK 1
#define IIC0_NACK 0
#define IIC0_WAIT 1
#define IIC0_NOWAIT 0

void IIC0_Init(void);   //works with both legacy and genericized projects

int IIC0_WaitForBus(void);
int IIC0_Addr(char Address, char Read, char Restart, char WaitForBus);
int IIC0_WriteByte(char Val, char Stop);
int IIC0_ReadByte(char *buff, char Ack, char Stop);
