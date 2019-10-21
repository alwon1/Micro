#include <stdtypes.h>
#include "./ryg_leds.h"
#include "derivative.h"
//extern volatile uint8_t PT1AD1;
//extern volatile uint8_t DDR1AD1;
//extern volatile uint8_t ATD1DIEN1; //dont need this

void Ryg_Init(void)
{
	PT1AD1 &= 0x1F;  //clear outputs do we need this
	DDR1AD1 |= 0xE0; //set direction to outputs on top 3 bits where LEDs located
	return;
}

void Ryg_All_On(void)
{
	PT1AD1 |= 0xE0;
	return;
}

void Ryg_All_Off(void)
{
	PT1AD1 &= 0x1F;
	return;
}

void Ryg_Sel_On(rygLed_t Leds)
{
	PT1AD1 |= Leds & (Red | Yellow | Green);//we or all the values together so its only defined in one spot with out affecting other bits
	return;
}
void Ryg_Sel_Off(rygLed_t Leds)
{
	PT1AD1 &= ~(Leds & (Red | Yellow | Green));
	return;
}
void Ryg_Set(rygLed_t Leds)
{
	PT1AD1 = PT1AD1 & ~(Red | Yellow | Green) | Leds;
}

void Ryg_Tog(rygLed_t Leds)
{
	PT1AD1 ^= Leds & (Red | Yellow | Green);
	return;
}

rygLed_t Ryg_Status(void)
{
	return PT1AD1 & (Red | Yellow | Green);
}