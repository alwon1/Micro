#include "7Seg.h"
#include "derivative.h"
#include "Util.h"
#define write(mode)                                                 \
	PORTA = (mode) == 0 ? (PORTA & 0xFC) : ((PORTA & 0xFE) | 0x02); \
	PORTA |= 0x01;

#define writeCtl()                   \
	PORTA = ((PORTA & 0xFE) | 0x02); \
	PORTA |= 0x01;

#define WriteDat() \
	PORTA &= 0xFC; \
	PORTA |= 0x01;

enum bla
{
	//Decimal = 1,
	BankA = 1 << 3,
	Run = 1 << 4,
	Nodecode = 1 << 5,
	Hex = (1 << 6),
	full = 1 << 7
};
unsigned int HEXTODEC(unsigned int val);
static unsigned char mode = BankA | Run; //holds values to be sent with ctrl words bootom 3 have own meaning

void SevSeg_Init(void)
{
	DDRA |= 0x03;
	DDRB = 0xff;
	SevSeg_BlAll();
	return;
}

void SevSeg_BlAll(void)
{
	int i = 0;
	PORTB = (mode & BankA) | full | Hex;
	writeCtl();
	PORTB = 0x80;
	for (i = 0; i < 8; i++) //reset all digits to zero
	{
		WriteDat();
	}
	PORTB = (mode & BankA) | full | Nodecode;
	writeCtl();
	PORTB = 0x80;			//disable decimal
	for (i = 0; i < 8; i++) //fill display with no decode blank digits
	{
		WriteDat();
	}
	return;
}
void SevSeg_Cust(unsigned char pos, unsigned char raw)
{
	PORTB = Nodecode | (pos & 0x07) | Run;
	writeCtl();
	PORTB = raw;
	WriteDat();
	return;
}
//function underlying all individual digit updates
void _Sev_SegBaseSendchar(unsigned char pos, unsigned char num, unsigned char coding)
{
	PORTB = ((coding & (Hex | Nodecode)) == 0 ? (mode & ~full) : (coding & (Hex | Nodecode | BankA | Run))) | (pos & 0x07); //follow specified then default to mode set
	writeCtl();

	PORTB =  (num & 0x8F);//allow decimal to be passed
	WriteDat();
	return;
}
//send based on current mode
void SevSeg_Char(unsigned char pos, unsigned char num)
{
	_Sev_SegBaseSendchar(pos, 0x80|num, mode);//disable decimal
	return;
}
void SevSeg_CharDecEn(unsigned char pos, unsigned char num)
{
	_Sev_SegBaseSendchar(pos, num, mode);
	return;
}
void SevSeg_BlChar(unsigned char pos)
{
	//0x80 so no decimal
	_Sev_SegBaseSendchar(pos, 0x80, mode & Nodecode);
	return;
}
//displays based on mode
void SevSeg_Top4(unsigned int val)
{
	unsigned char i;
	//unsigned int val =val1 ;

	val = Util_Binary_To_BCD_uI(val);

	for (i = 0; i < 4; i++)
	{
		PORTB = Hex | Run | BankA | (3 - i);
		writeCtl();
		PORTB = (val >> (4 * i)) | 0x80;
		WriteDat();
	}
	return;
}
void SevSeg_Bot4(unsigned int val)
{
	unsigned char i;
	val = Util_Binary_To_BCD_uI(val);
	for (i = 0; i < 4; i++)
	{
		PORTB = Hex | Run | BankA | (7 - i);
		writeCtl();
		PORTB = (val >> (4 * i)) | 0x80;
		WriteDat();
		//_Sev_SegBaseSendchar(i, val & (0x000F << 4 * i), mode|Hex);
	}
	return;
}


void SevSeg_dChar(unsigned char, unsigned char);