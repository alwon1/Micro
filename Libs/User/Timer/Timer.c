#include "Timer.h"
#include "derivative.h"
#include <stdlib.h>
#define CLOCK (8000 * 1000)
#define CLOCK_nS ((1000 * 1000 * 1000) / (CLOCK))
#define MICRO_PRESCALE(timeNs) ((timeNs) / CLOCK_nS)
//CAPTURE TIMER
void Timer_Init8us(void)
{
    TSCR1 |= 0x80;
    TSCR2 &= 0XF8;
    TSCR2 |= 6;    //i think this should leave the rest of the register alone sets our prescale to 64
    TIOS |= 1;     //set IOS to output Compare
    TCTL2 &= 0XFC; //enable toggle tWo lines
    TCTL2 |= 1;
    TFLG1 |= 1;
}
void Timer_Init_1us(void)
{
    TSCR1 |= 0x80;
    TSCR2 &= 0XF8;
    TSCR2 |= 3;    //i think this should leave the rest of the register alone sets our prescale to 64
    TIOS |= 1;     //set IOS to output Compare
    TCTL2 &= 0XFC; //enable toggle tWo lines
    TCTL2 |= 1;
    TFLG1 |= 1;
}
void Timer_Init_125ns(void)
{
    TSCR1 |= 0x80;
    TSCR2 &= 0XF8;
    TSCR2 |= 0;    //i think this should leave the rest of the register alone sets our prescale to 64
    TIOS |= 1;     //set IOS to output Compare
    TCTL2 &= 0XFC; //enable toggle tWo lines
    TCTL2 |= 1;
    TFLG1 |= 1;
}

void Sleep_ms(unsigned int iTime)
{
    unsigned int iCount;
    TC0 = TCNT + 125;
    for (iCount = 0; iCount < iTime; iCount++)
    {
        TFLG1 = 1;
        while (TFLG1_C0F == 0)
            ;
        TC0 += 125;
    }
}
