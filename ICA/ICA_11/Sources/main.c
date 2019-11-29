#include "SCI0.h"
#include "Util.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */

void main(void)
{
  /* put your own code here */
  SCI0_Init19200();
  //EnableInterrupts;

  for (;;)
  {
    char a, b, c;
    SCI0_TxString("\tPositive Adding\r\n\tA=");
    while (a = Util_ch_To_Ch(SCI0_RxChar()) == 0xff)
      ;
    SCI0_TxString("\r\n\tB=");
    while (b = Util_ch_To_Ch(SCI0_RxChar()) == 0xff)
      ;
    SCI0_TxString("\r\nA+B=");
    c = a + b;
    c = Util_Binary_To_BCD_uI(c);
    SCI0_TxChar((char)(c >> 4) + '0');
    SCI0_TxChar((char)(c) + '0');
    //_FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
