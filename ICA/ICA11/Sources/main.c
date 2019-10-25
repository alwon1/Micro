#include "SCI0.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */
#include <stdlib.h>
#include <stdtypes.h>
#include <string.h>
char GetSCI0Num(void);
char AsciToNum(char ch);
void Menu(void);
void ByteToAscii(char val, char *buff);
void main(void)
{
  /* put your own code here */
  SCI0_Init19200();

  //EnableInterrupts;
  Menu();
  for (;;)
  {

    //_FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
void Menu(void)
{
  char A = 0, B = 0;
  char C[4];
  SCI0_TxString("Positive Adding\r\n\n\tA= ");
  A = GetSCI0Num();
  SCI0_TxString("\r\n\tB= ");
  B = GetSCI0Num();
  ByteToAscii(A + B, C);
  SCI0_TxString("\r\nA + B = ");
  SCI0_TxString(C);
  return;
}
//transmits when it recives one
char GetSCI0Num(void)
{
  char X = 0;
  do
  {
    X = SCI0_RxChar();
  } while (X < '0' || X > '9');
  SCI0_TxChar(X);

  return X - '0';
}

void ByteToAscii(char val, char *buff)
{
  char i =0;
if (val>=100)
{
  buff[i++] = (val / 100) + '0';
  val -= (val / 100) * 100;
}
if (val>=10)
{
    buff[i++] = (val / 10) + '0';
  val -= (val / 10) * 10;
}
  buff[i++] = val + '0';
  buff[i] = 0;
}
char AsciToNum(char ch)
{
  if (ch >= '0' && ch <= '9')
  {
    return ch - '0';
  }
  return ~0; //oxff is our fail code
}
