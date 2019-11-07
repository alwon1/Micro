#include "7Seg.h"
#include "Timer.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */

void main(void)
{
  /* put your own code here */

  _DISABLE_COP();
  SevSeg_Init();
  // EnableInterrupts

  for (;;)
  {
    //_FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

void TI10ms(void)
{
  Timer_Init8us();
}
void TimInter(void)
{
  volatile static unsigned long int count = 0;
  TC0 += 1250;
  TFLG1 = 1;
  SevSeg_Top4(count / 100);
  SevSeg_Bot4(count % 100);
}