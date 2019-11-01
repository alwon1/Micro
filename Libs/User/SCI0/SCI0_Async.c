#include "derivative.h"
#include <stdlib.h>
//buffer is 256 as that the max size we can index with a uchar
volatile static char Rx_Buff[256];
volatile static char Tx_Buff[256];
//we read from start and insert at end (the last byte to read is the byte before end)
volatile static unsigned char Rx_Start = 0, Rx_End = 0, Tx_Start = 0, Tx_End = 0;
//stores the location of a newline in a bitfield the size of the buffers
volatile static char NewLine_Loc[32];

//this function also clears buffers
void SCI0_Async_Init(void)
{
    char i;
    SCI0CR2_TIE = 0;
    SCI0CR2_RIE = 0;
    for (i = 0; i < 128; i++)
    {
        //because an int is twice the size of char doing this is less loop itterations
        //Note: Reamember we are big Edian
        (int)Rx_Buff[i * 2 + 1] = 0;
        (int)Tx_Buff[i * 2 + 1] = 0;
        NewLine_Loc[i / 8] = 0;
    }
    Rx_Start = Rx_End = Tx_Start = Tx_End = 0;
    SCI0CR2_RIE = 1;
}

void SCI0_Async_Enable(void)
{
    SCI0CR2_TIE = 0;
    SCI0CR2_RIE = 1;
}

void _SCI0_Async_Rx(void)
{
    Rx_Buff[Rx_End] = SCI0DRL;
    //if we recived a newline track it for the readline function
    if (Rx_Buff[Rx_End] == '\n')
    {
        NewLine_Loc[Rx_End / 8] = 1 << (Rx_End % 8);
    }
    Rx_End++;
    //check that we have room in our buffer
    if (Rx_End == Rx_Start)
    {
        SCI0CR2_RIE = 0;
    }
    return;
}
void _SCI0_Async_Tx(void)
{
    SCI0DRL = Tx_Buff[Tx_Start++];
    //is the buffer Empty then stop transmiting for now
    if (Tx_Start == Tx_End)
    {
        SCI0CR2_TIE = 0;
    }
    return;
}

char SCI0_A_ReadChar(void)
{
    if (Rx_End != Rx_Start)
    {
        //if the charector is a new line we need to maintain the newline locator
        if (Rx_Buff[Rx_Start] == '\n')
        {
            NewLine_Loc[Rx_Start / 8] ^= 1 << (Rx_Start % 8);
        }
        return Rx_Buff[Rx_Start++];
    }
    return 0;
}

char *SCI0_A_ReadLine(void)
{
    char *Res;
    char i, i2 = 0, i3;
    for (i = Rx_Start / 16; i < 16; i++)
    {
        if ((int)NewLine_Loc[i * 2 + 1] != 0)
        {
            char size;
            char Add1 = (NewLine_Loc[i * 2] != 0) ? 1 : 0;
            while ((NewLine_Loc[i * 2] & 1 << i2++) == 0)
                ;
            //we have found the end
            size = (i * 2 * 8 + i2 + Add1) - Rx_Start;
            Res = malloc(size + 1);
            for (i3 = 0; i < size - Rx_Start; i3++)
            {
                Res[i3] = SCI0_A_ReadChar();
            }
            Res[size] = 0;
            return Res;
        }
    }

    //there is no complete line then
    Res = malloc(sizeof(""));
    *Res = "";
    return Res;
}