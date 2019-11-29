#include "7Seg.h"
#include "Switch.h"
#include "Timer.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */
void main(void)
{
  /* put your own code here */
  unsigned int val = 0;
  unsigned char Ls = 0; //track what are current timer delay is
  Switch_Init();
  SevSeg_Init();
  Timer_Init8us();
  EnableInterrupts;

  for (;;)
  {
    //_FEED_COP(); /* feeds the dog */
    if (Switch_Raw() & Mid)
    {
      while (Switch_Raw() & Mid);

      Ls = Ls == 1 ? 0 : 1;
      if (Ls == 0)
      {
        Timer_Init8us();
      }
      else
      {
        Timer_Init_125ns();
      }
    }

    Sleep_ms(100);
    val = val == 9999 ? 0 : val + 1;
    SevSeg_Top4(val);
  } /* loop forever */
  /* please make sure that you never leave main */
}
