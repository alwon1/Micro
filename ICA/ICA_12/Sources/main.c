#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */
//#define interrupt
//#define VectorNumber_Vsci0
#include "SCI0.h"

void _Vsci0_RxItr(void);

void main(void)
{
  /* put your own code here */

  _DISABLE_COP();
  SCI0_Init19200();
  EnableInterrupts;
  SCI0CR2_RIE = 1;
  for (;;)
  {
    asm wai;
    //_FEED_COP(); /* feeds the dog */
  }              /* loop forever */
  /* please make sure that you never leave main */
}

interrupt VectorNumber_Vsci0 void _Vsci0_RxItr(void)
{
  char temp;
  if (SCI0SR1_RDRF)
  {
    temp = SCI0DRL;
    SCI0DRL = temp;
  }
  return;
}