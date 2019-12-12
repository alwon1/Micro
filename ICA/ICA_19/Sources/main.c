#include "PWM.h"
#include "delay.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */
#include "I2C.h"
void main(void)
{
  /* put your own code here */
  int x, y, z = 0;
  PWM_Init();
  IIC0_ReadByte()
  //EnableInterrupts;

  for (;;)
  {
    PWM_SetDutyHalfCh(PWM3_LCD_BK, x++ % 200);
    PWM_SetDutyHalfCh(PWM0_RGB_B, x+50 % 200);
    PWM_SetDutyHalfCh(PWM1_RGB_G, x-25 % 200);
    PWM_SetDutyHalfCh(PWM4_RGB_R, x  % 200);
    Delay_C(25);
    //_FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
