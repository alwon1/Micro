#include "PWM.h"
#include "derivative.h"
#include <hidef.h>

static char Brighness = 255;
//1 byte per color max accuracy at full brightness
RGB_SetColor(unsigned char Red, unsigned char Blue, unsigned char Green)
{
    PWM_SetDutyHalfBtCh(PWM4_RGB_R, Red % Brighness);
    PWM_SetDutyHalfBtCh(PWM1_RGB_G, Blue % Brighness);
    PWM_SetDutyHalfBtCh(PWM0_RGB_B, Green % Brighness);
}
RGB_Brightness(unsigned char val)
{
    Brighness = val
}