#include "7Seg.h"
#include "ATD.h"
#include "I2C.h"
#include "PWM.h"
#include "Timer.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */
void TI10ms(void);

void main(void)
{
  /* put your own code here */
  TI10ms();
  ATD_Init();
  SevSeg_Init();
  IIC0_Init();
  //excluding because we want it inverted today
  //PWM_Init();
  PWM_SetFrequency(PWM6_SPK, 40000);
  PWM_SetDutyHalfCh(PWM6_SPK, 30 * 2);

  EnableInterrupts;

  for (;;)
  {
    //_FEED_COP(); /* feeds the dog */
    asm wai;
  } /* loop forever */
  /* please make sure that you never leave main */
}
void TI10ms(void)
{
  Timer_Init8us();
  TIE = 1;
}
//enum Ch{A=0,B=1}
void Dac(unsigned int val, unsigned char ch)
{

  //IIC0_Addr(0x10, 0, 1, 0);
  val *=16		   ;
  while (IIC0_IBSR & 0x20) //wait
  {
    /* code */
  }
  IIC0_IBCR |= 0x30; //set as master
  IIC0_IBDR = 0x20;
  while (!(IIC0_IBSR & 0x02)) //eait for flag
  {
    /* code */
  }
  IIC0_IBSR |= 0x02;
  IIC0_IBDR = ch;
  while (!(IIC0_IBSR & 0x02))
    ; //eait for flag
  {
    /* code */
  }
  IIC0_IBSR |= 0x02;
  IIC0_IBDR = (unsigned char)(val / 256);
  while (!(IIC0_IBSR & 0x02))
    ; //eait for flag
  {
    /* code */
  }
  IIC0_IBSR |= 0x02;
  IIC0_IBDR = (unsigned char)(val &0x00ff);
 while (!(IIC0_IBSR & 0x02))
    ; //eait for flag
  {
    /* code */
  }
  IIC0_IBCR &= 0xCF;
  IIC0_IBSR |=0x02;
  return;
}
interrupt VectorNumber_Vtimch0 void TimInter(void)
{
  volatile static unsigned long int count = 0;
  unsigned int r = 0;
  volatile unsigned int t = 0;
  r = ATD_Read();
  TC0 += 625;
  TFLG1 = 1;
  //SevSeg_Top4(count / 100);
  //SevSeg_Bot4(count % 100);
  count = count >= 999999 ? 0 : count + 1;
  r = ATD_Read();
  t = (r * 10) / 2;
  SevSeg_Top4(t);
  Dac(t, 0x30);
  Dac(4000-t, 0x31);
  t /= 40;
  t = t > 100 ? 100 : t;
  PWM_SetDutyHalfCh(PWM6_SPK, t * 2);
}