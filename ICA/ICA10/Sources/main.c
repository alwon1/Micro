#include "SCI0.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>		/* common defines and macros */
 char * line = "Welcome to the world of serial communication\r\n";
void main(void)
{
	/* put your own code here */

	//EnableInterrupts;
	//SCI0_Init19200();
	SCI0_Init(300);
	SCI0_TxString(line);
	for (;;)
	{
		char x=SCI0_RxChar();
		if ((x))
		{
			SCI0_TxChar(x);
		}
		//_FEED_COP(); /* feeds the dog */
	} /* loop forever */
	  /* please make sure that you never leave main */
}
