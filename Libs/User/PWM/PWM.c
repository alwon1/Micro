#include "PWM.h"
#include "derivative.h"
#include <hidef.h>
#define clock 8000000

//Note: RGB LED is on clock A, Backlight and speaker are on clock B
//      the RGB LED and the Backlight wont touch the frequency of there channels or clocks
//      this gives users of the remaining channels some flexibility as long as the primary clocks dont scale to low

void PWM_Init(void)
{
    PWMPOL = ~0;
}

void PWM_SetFrequency(PWM_Channel channel, unsigned long frequency)
{
    //this is basic with no scalling only channel 0 can be generallized later
    //this is not rounded

    //need to finish this
    //int clockscale = clock/frequency/255

    *((&PWMPER0) + channel) = clock / frequency;
    //50% duty cycle
    *((&PWMDTY0) + channel) = *((&PWMPER0) + channel) >> 1;
    PWME |= 0x01 << channel;
    return;
}
//dont forget to set PWM up as it deafults to inverted output
//Sets PWM Output to a Half Percentage point
void PWM_SetDutyHalfCh(PWM_Channel channel, unsigned char duty)
{
    //test for backlight
    *((&PWMPER0) + channel) = 200;
    *((&PWMDTY0) + channel) = duty;
    PWME |= 0x01 << channel;
    return;
}
void PWM_SetDutyHalfBtCh(PWM_Channel channel, unsigned char duty)
{
    //test for backlight
    *((&PWMPER0) + channel) = 0xff;
    *((&PWMDTY0) + channel) = duty;
    PWME |= 0x01 << channel;
    return;
}

void PWM_SetDutyHalf(PWM_Channel channel, float duty)
{
    PWMPER0 = 200;
    PWMDTY0 = ((char)(duty * 2)) % 200;
    return;
}
//dont worry shoudnot matter for LED
