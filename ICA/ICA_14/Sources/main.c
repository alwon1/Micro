#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "time.h"
#include "7Seg.h"




void main(void) {
  /* put your own code here */
  

  Timer_Init8us();
	//\   `EnableInterrupts;


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
