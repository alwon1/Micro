#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>		/* common defines and macros */

void main(void)
{
	/* put your own code here */

	EnableInterrupts;

	for (;;)
	{
		_FEED_COP(); /* feeds the dog */
	}				 /* loop forever */
					 /* please make sure that you never leave main */
}
