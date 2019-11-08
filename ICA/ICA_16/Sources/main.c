#include "7Seg.h"
#include "Timer.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */

void TI10ms(void);
void main(void)
{
  /* put your own code here */

  _DISABLE_COP();
  SevSeg_Init();
  TI10ms();
  EnableInterrupts

      for (;;)
  {
    asm wai;
    //_FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

void TI10ms(void)
{
  Timer_Init8us();
  TIE = 1;
}
interrupt VectorNumber_Vtimch0 void TimInter(void)
{
  volatile static unsigned long int count = 0;
  TC0 += 1250;
  TFLG1 = 1;
  SevSeg_Top4(count / 100);
  SevSeg_Bot4(count % 100);
  count = count >= 999999 ? 0 : count + 1;
}