#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>		/* common defines and macros */

#include "LCD.h"
#include "SCI0.h"
#include "ryg_leds.h"
void Main_Menu(void);
void LED_Menu(void);
void LCD_Menu(void);
void Term_Reset(void);

void main(void)
{
	/* put your own code here */
	LCD_Init();
	Ryg_Init();
	SCI0_Init(19200);
	//EnableInterrupts;
	Main_Menu();
	for (;;)
	{
	}
	/* please make sure that you never leave main */
}
void Main_Menu(void)
{

	for (;;)
	{
		Term_Reset();
		SCI0_TxString("Main Menu\r\n\t1. LEDs\r\n\t2. LCD\r\n");
		for (;;)
			switch (SCI0_RxChar())
			{
			case '1':
				LED_Menu();
				Term_Reset();
				SCI0_TxString("Main Menu\r\n\t1. LEDs\r\n\t2. LCD\r\n");
				break;

			case '2':
				LCD_Menu();
				Term_Reset();
				SCI0_TxString("Main Menu\r\n\t1. LEDs\r\n\t2. LCD\r\n");
				break;

			default:

				break;
			}
	}
	return;
}
void LED_Menu(void)
{
	Term_Reset();
	SCI0_TxString(
"LED Menu\r\n\
\t1. Red On\r\n\
\t2. Yellow On\r\n\
\t3. Green On\r\n\
\t4. Red Off\r\n\
\t5. Yellow Off\r\n\
\t6. Green Off\r\n\
\t7. All On\r\n\
\t8. All off\r\n\
\tM. Main Menu\r\n");
	for (;;)
	{
		switch (SCI0_RxChar())
		{
		case '1':
			Ryg_Sel_On(Red);
			break;

		case '2':
			Ryg_Sel_On(Yellow);
			break;

		case '3':
			Ryg_Sel_On(Green);
			break;

		case '4':
			Ryg_Sel_Off(Red);
			break;

		case '5':
			Ryg_Sel_Off(Yellow);
			break;

		case '6':
			Ryg_Sel_Off(Green);
			break;

		case '7':
			Ryg_All_On();
			break;

		case '8':
			Ryg_All_Off();
			break;

		case 'M':
		case 'm':
			return;
			break;

		default:
			break;
		}
	}
	return;
}
void LCD_Menu(void)
{
	Term_Reset();
	SCI0_TxString(
		"LED Menu\r\n\t1. Clear LCD Screen\r\n\t2. Display LCD Story\r\n\tM. Main Menu\r\n");
	for (;;)
	{
		switch (SCI0_RxChar())
		{
		case '1':
			//should replace with clear cmd but feeling lazy
			LCD_Init();
			break;

		case '2':
			LCD_String("Once upon a time,\nthere were 3 bears,\nwho lived in a house\nin the big woods.");
			break;

		case 'M':
		case 'm':
			return;
			break;

		default:
			break;
		}
	}
	return;
}
void Term_Reset(void)
{
	SCI0_TxString("\x1b[2J");
	SCI0_TxString("\x1b[H");
	return;
}