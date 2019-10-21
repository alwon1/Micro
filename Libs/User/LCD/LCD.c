
#include "derivative.h"
#include "LCD.h"
#include "delay.h"
#define PKEnable (0x01)
#define PKR_W (0x02)
#define PKRegSel (0x04)
#define lines2 (1 << 3)
#define LCDdatalength8 (1 << 4)
#define setFunction (1 << 5)
#define clearPK() (PORTK &= ~0x07)
#define setPK(val) PORTK |= ((val)&0x07)

static unsigned char x=0,y=0;
void LCD_Init(void)
{
	PORTK = 0x00;
	DDRK |= 0x7; //bottom 3 bits
	PTH = 0x00;
	DDRH = 0xFF;
	PTH = lines2 | LCDdatalength8 | setFunction;
	Delay_C(25); //wait for power up

	setPK(PKEnable);
	//Short_Delay();
	clearPK();
	Delay_C(5); //only need 4.1 here

	setPK(PKEnable);
	//Short_Delay();
	clearPK();
	Delay_C(1); //only need 100us here but whatever

	setPK(PKEnable);
	//Short_Delay();
	clearPK();
	LCD_Ctrl(lines2 | LCDdatalength8 | setFunction);
	LCD_Ctrl(0x01); //clear display
	LCD_Ctrl(0x0F); //turn on display and curser
	LCD_Ctrl(0x06); //increment address and write left to right
	return;
}
void LCD_Ctrl(unsigned char ctl)
{
	while (LCD_Busy());
	PTH = ctl;
	Short_Delay();
	setPK(PKEnable);
	Short_Delay();
	clearPK();
	PTH = 0;
	return;
}
unsigned char LCD_Busy(void)
{
	unsigned char res;
	DDRH = 0x00; //set as inputs
	setPK(PKR_W);
	setPK(PKEnable);
	Short_Delay();
	res = PTH & 0x80;
	clearPK();
	PTH = 0;
	DDRH = 0xFF;
	return res;
}

void LCD_Addr(unsigned char addr)
{
	LCD_Ctrl(addr | 0x80);
	//PTH = addr
	return;
}
void LCD_Char(unsigned char ch)
{	//for special charactor detection
	switch(ch)
	{
		case '\n':
			LCD_Pos(++y,0);
	 		break;
			
	 	case '\t':
			if(x<=18) LCD_Pos(y,(x+2));
			else LCD_Pos(++y,2);
			break;
			
		default:			
			while (LCD_Busy());	
			PTH = ch;
			setPK(PKEnable | PKRegSel);
			Short_Delay();
			clearPK();
			PTH = 0;
			if (x++==20)
			{
				y++;
				x=0;
				LCD_Pos(y,x);	
			}
			break;
	}
	return;
}
void LCD_Pos(unsigned char Row, unsigned char Col)
{
	if (Col > 19)
	{
		return;
	}
	switch (Row)
	{
		case 0:
			LCD_Addr(Col);
			break;

		case 1:
			LCD_Addr((unsigned char)(Col+0x40));
			break;
			
		case 2:
			LCD_Addr((unsigned char)(Col+0x14));
			break;
			
		case 3:
			LCD_Addr((unsigned char)(Col+0x54));
			break;
			
		default:
			break;
	}
	
	return;
}
void LCD_String(char *str)
{
	int i;
	for (i = 0; str[i] != 0; i++)
	{			
		LCD_Char(str[i]);
	}
	return;
}
