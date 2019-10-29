
#include "SCI0.h"
#include "derivative.h"
#include <stdlib.h>
#include <stdtypes.h>
#define Clock ((unsigned long)8000000)
#define Clock16 ((unsigned long)(8000000 / 16))

static char Txbuff[256];
static char Rxbuff[256];
volatile static unsigned char newlineloc[256];
volatile static unsigned char newlinelocEnd = 0;
volatile static unsigned char newlinelocStart = 0;
//static unsigned char Txpos = 0;
volatile static unsigned char TxStart = 0;
volatile static unsigned char TxEnd = 0;

volatile static unsigned char Rx_Data_Start = 0;
volatile static unsigned char Rx_Data_End = 0;

volatile static Bool Tx_Data_Avalible = 0;
//volatile static unsigned char Newlines_Avalible = 0;
//overflow
volatile static Bool Rx_Buff_Over = FALSE;

//interrupt VectorNumber_Vsci0
void SCI0Rx(void)
{
	if (SCI0SR1_RDRF) //if a byte has been recieved
	{
		Rxbuff[++Rx_Data_End] = SCI0DRL;
		if (Rxbuff[Rx_Data_End] == '\n')
			newlineloc[newlinelocEnd++] = Rx_Data_End;

		//works beacuse of wrap around
		SCI0CR2_RIE = Rx_Data_Start == Rx_Data_End ? 0 : 1;
	}
	//if we can transmit new data
	if (SCI0SR1_TDRE)
	{
		SCI0DRL = Txbuff[TxStart++];
		SCI0CR2_TIE = Tx_Data_Avalible = TxStart != TxEnd ? TRUE : FALSE;
	}
}

//not finished but good for other inits need to check if valid
void SCI0_Init(unsigned long baud) //any valid baud rate can be passed to this; 8-bit, 1 Stop, No parity, no interrupts
{
	//baud rate is clock /16*SBr
	//or
	//divisor = (clock/baud)/16
	//unsigned int divisor;
	//round clockrate
	SCI0BD = (unsigned int)(Clock16 / (baud));
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
	Txbuff[TxEnd++] = ch;
	SCI0CR2_TIE = Tx_Data_Avalible = TRUE;
	return;
}
unsigned char SCI0_RxChar(void) //Non-blocking; returns NULL if no new valid character is available
{

	return Rx_Data_Start == Rx_Data_End ? 0 : Rxbuff[Rx_Data_Start++];
}

void SCI0_ReadLine(char **buff)
{
	unsigned char i = 0;
	unsigned char s = newlineloc[newlinelocStart++] - Rxbuff[Rx_Data_Start];
	*buff = malloc(sizeof(char) * s);
	for (i = 0; i < s; i++)
	{
		*buff[i] = Rxbuff[Rx_Data_Start++];
	}
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