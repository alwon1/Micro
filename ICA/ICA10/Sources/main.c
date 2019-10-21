#include "SCI0.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>		/* common defines and macros */
void main(void)
{
	/* put your own code here */

	//EnableInterrupts;
	SCI0_Init19200();
	SCI0_TxString("Welcome to the world of serial communication\r\n");
	for (;;)
	{
		char x;
		if ((x = SCI0_RxChar()))
		{
			SCI0_TxChar(x);
		}
		//_FEED_COP(); /* feeds the dog */
	} /* loop forever */
	  /* please make sure that you never leave main */
}
