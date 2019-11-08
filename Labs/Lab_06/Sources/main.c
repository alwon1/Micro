#include "7Seg.h"
#include "Timer.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */
void TI10ms(void);
void capTime(void);
void BotUp(void);
void PTJStart(void);
void main(void)
{
  /* put your own code here */
  SevSeg_Init();
  capTime();
  EnableInterrupts;
  PTJStart();
  TI10ms();
  for (;;)
  {
    asm wai;
    //_FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
volatile unsigned long int TimeCount = 0;
void capTime(void)
{
  SevSeg_Char(3, (TimeCount / 100) % 10);
  SevSeg_Char(2, (TimeCount / 1000) % 6);
  SevSeg_CharDecEn(1, (TimeCount / 6000) % 10);
  SevSeg_Char(0, (TimeCount / 60000) % 10);
}
interrupt VectorNumber_Vtimch0 void TimInter(void)
{
  TimeCount++;
  TC0 += 1250;
  TFLG1 = 1;

  BotUp();
}
void BotUp(void)
{
  SevSeg_Char(7, TimeCount % 10);
  SevSeg_Char(6, (TimeCount / 10) % 10);
  SevSeg_CharDecEn(5, (TimeCount / 100) % 10);
  SevSeg_Char(4, (TimeCount / 1000) % 6);
}
interrupt VectorNumber_Vportj void PJInterupt(void)
{
  if (PIFJ_PIFJ1)
  {
    PIFJ_PIFJ1 = 1;
  }
  if (PIFJ_PIFJ0)
  {
    PIFJ_PIFJ0 = 1;
    capTime();
  }
}
void PTJStart(void)
{
  PPSJ_PPSJ0 = 1; //interupt on rising ie when pressed
  PIEJ = 0x03;
}
void TI10ms(void)
{
  Timer_Init8us();
  //Timer_Init_125ns();
  TIE = 1;
}