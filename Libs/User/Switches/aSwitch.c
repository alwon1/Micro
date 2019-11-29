#include "Timer.h"
#include "derivative.h"
#include <hidef.h>

typedef enum
{
    Up,
    Down,
    Left,
    right,
    Mid,
    Center
} Switches;
static Switches Pressed;
static Switches Released;

void Switches_Async_Init(void);

Switches Switches_GetRaw(void);

Switches Switches_IsDown(Switches switches);
//gets switches whose state has changed to down after the last check even if it is now released
Switches Switches_GetPressed(void);
Switches Switches_GetReleasd(void);

void Switches_Async_Init(void)
{

    PITCE_PCE0 = 1;   //enable imer 0
    PITMUX_PMUX0 = 0; //use microtimer 0
    PITCFLMT = 0xa0;
    PITLD0 = 500;       //12.5ms for debounce
    PITMTLD0 = 200;     // 25us
    PITINTE_PINTE0 = 1; //enable interupts
}
//this is the ISR
void ASwitchUp(void)
{
    Switches temp = Switches_GetRaw();
    Released |= Pressed ^ (temp & Pressed);
    Pressed |= temp;
    return;
}

Switches Switches_GetPressed(void)
{
    Switches temp = Pressed;
    Pressed = 0;
    return temp;
}

Switches Switches_GetReleasd(void)
{
    Switches temp = Released;
    Released = 0;
    return temp;
}