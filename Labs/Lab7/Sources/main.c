#include "ATD.h"
#include "PWM.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */
void PWM_test(void);
void main(void)
{
  int x;
  /* put your own code here */
  ATD_Init();
  PWM_Init();
  PWM_test();
  EnableInterrupts;

  for (;;)
  {
    x = ATD_Read();
    x/=8;
    PWM_SetDutyHalfCh(PWM4_RGB_R, (char)(x));
    PWM_SetDutyHalfCh(PWM1_RGB_G, 50 - (char)(x ));
    
    //_FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
//sets frequency to 150hz
void PWM_test(void)
{
  PWMPRCLK |= 0x07;
  PWMSCLA = 251;
}
