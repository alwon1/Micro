#include "Switch.h"
#include "Timer.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */

void repdelay(void);
void bl(void);
void main(void)
{
  /* put your own code here */
  char state = 0;
  Switch_Init();
  Timer_Init8us();

  //EnableInterrupts;

  for (;;)
  {
    if (Switch_Raw() & Mid)
    {
      while (Switch_Raw() & Mid)
        ;
      state = state < 4 ? state + 1 : 0;
    }
    switch (state)
    {
    case 0:
      Timer_Init8us();
      while (!(Switch_Raw() & Mid))
        repdelay();
      break;

    case 1:
      Timer_Init8us();
      while (!(Switch_Raw() & Mid))
      {
        bl();
      }
      break;

    case 2:
      Timer_Init_125ns();
      while (!(Switch_Raw() & Mid))
        repdelay();
      break;

    case 3:
      Timer_Init_125ns();
      while (!(Switch_Raw() & Mid))
        bl();
      break;

    default:
      break;
    }
    //_FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
void repdelay(void)
{
  int i;
  for (i = 0; i < 100; i++)
  {
    TFLG1 = 1;
    while (TFLG1_C0F == 0)
      ;
    TC0 = TCNT + 100;
  }
  return;
}
void bl(void)
{
  int i;
  for (i = 0; i < 100; i++)
  {
    TFLG1 = 1;
    while (TFLG1_C0F == 0)
      ;
    TC0 += 100;
  }
}
