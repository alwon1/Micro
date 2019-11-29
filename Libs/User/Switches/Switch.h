#ifndef SWITCH_H
#define SWITCH_H

typedef enum
{
	Up = 0x10,
	Left = 0x08,
	Down = 0x04,
	Right = 0x02,
	Mid = 0x01
} Switch_t;

void Switch_Init(void);//enables all switches

void Switch_Enable(Switch_t switches);
void Switch_Disable(Switch_t switches);

Switch_t Switch_Active(void);//returns switches that are currently enabled
char Switch_IsActive(Switch_t switches);//returns one if the selected switches are enabled

Switch_t Switch_Raw(void);//returns raw switch values with no filtering or checking if they are enabled

Switch_t Switch_Down(void);//returns all active switches which are down
char Switch_IsDown(Switch_t switches);// returns 1 if all switches passed are down

Switch_t Switch_Up(void);//returns all active switches which are up
char Switch_IsUp(Switch_t switches);// returns 1 if all switches passed are up
#endif