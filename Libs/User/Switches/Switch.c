#ifndef VSCODE
#include "derivative.h"
#else
#include <stdint.h>
#include "..\VSderive/VSderive.h"
#endif
#include "./Switch.h"

void Switch_Init(void) //enables all switches
{
	ATD1DIEN1 |= 0x1F;
	DDR1AD1 &= 0xE0;
	return;
}

void Switch_Enable(Switch_t switches)
{
	ATD1DIEN1 |= switches & (Up | Left | Down | Right | Mid);
	DDR1AD1 &= ~(switches & (Up | Left | Down | Right | Mid));
	return;
}
void Switch_Disable(Switch_t switches)
{
	ATD1DIEN1 &= ~(switches & (Up | Left | Down | Right | Mid));
	DDR1AD1 |= switches & (Up | Left | Down | Right | Mid);
	return;
}

Switch_t Switch_Active(void) //returns switches that are currently enabled
{
	return ATD1DIEN1 & ~DDR1AD1 & (Up | Left | Down | Right | Mid);
}
char Switch_IsActive(Switch_t switches) //returns one if the selected switches are enabled
{
	return (ATD1DIEN1 & ~DDR1AD1 & switches & (Up | Left | Down | Right | Mid)) == switches ? 1 : 0;
}

Switch_t Switch_Raw(void) //returns raw switch values with no filtering or checking if they are enabled we still filterout things that are never a switch
{
	return PT1AD1 & (Up | Left | Down | Right | Mid);
}

Switch_t Switch_Down(void) //returns all active switches which are down
{
	return Switch_Active() & PT1AD1;
}
char Switch_IsDown(Switch_t switches) // returns 1 if all switches passed are down
{
	return (Switch_Active() & switches) == switches ? 1 : 0;
}

Switch_t Switch_Up(void) //returns all active switches which are up
{
	Switch_t temp = Switch_Active();
	return (temp & PT1AD1) ^ temp;
}
char Switch_IsUp(Switch_t switches) // returns 1 if all switches passed are up
{
	return (Switch_Up() & switches) == switches ? 1 : 0;
}