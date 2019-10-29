
#include "SCI0.h"
#include "derivative.h"
#define Clock ((unsigned long)8000000)
#define Clock16 ((unsigned long)(8000000/16))
static char buff[255];
static char *buffEnd = &buff[0];
static char over = 0;
//not finished but good for other inits need to check if valid
void SCI0_Init(unsigned long baud) //any valid baud rate can be passed to this; 8-bit, 1 Stop, No parity, no interrupts
{
	//baud rate is clock /16*SBr
	//or
	//divisor = (clock/baud)/16
	//unsigned int divisor;
	//round clockrate
	SCI0BD =  (unsigned int)(Clock16 / (baud));
	SCI0CR1 = 0;
	//enable transmit and recive no interupts
	SCI0CR2 = (1 << 2) | (1 << 3);
	return;
}
void SCI0_Init9600(void) //8-bit, 1 Stop, No parity, no interrupts
{
	SCI0_Init(9600);
	return;
}
void SCI0_Init19200(void) //8-bit, 1 stop, No parity, no interrupts
{
	SCI0_Init(19200);
	return;
}
void SCI0_TxChar(unsigned char ch)
{
	while (!SCI0SR1_TDRE)
	{
		/*if (SCI0SR1_RDRF)
		{
			*buffEnd = SCI0DRL;
			if (++buffEnd == &buff[254])
			{
				over = 1;
				buffEnd = &buff[0];
			}
		}*/
	}
	SCI0DRL = ch;
	return;
}
unsigned char SCI0_RxChar(void) //Non-blocking; returns NULL if no new valid character is available
{
	//if (buffEnd != &buff[0])
	//{
	//	buffEnd--;
	//	return *buffEnd;
	//}
	if (SCI0SR1_RDRF)
	{
		return (unsigned char)SCI0DRL;
	}
	return 0;
}
void SCI0_TxString(char *str)
{
	char x;
	do
	{
		x = *(str++);
		SCI0_TxChar(x);
	} while (x);
	return;
}