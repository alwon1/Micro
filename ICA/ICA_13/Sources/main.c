#include "7Seg.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */

void PTJStart(void);
void main(void)
{
  /* put your own code here */
  SevSeg_Init();
  SevSeg_Top4(0);
  PTJStart();

  EnableInterrupts;

  for (;;)
  {
    //_FEED_COP(); /* feeds the dog */
    asm wai;
  } /* loop forever */
  /* please make sure that you never leave main */
}
interrupt VectorNumber_Vportj void PJInterupt(void)
{
  volatile static unsigned int val = 0;
  if (PIFJ_PIFJ1)
  {
    PIFJ_PIFJ1 = 1;
    val = val == 0 ? 9999 : val - 1;
    //SevSeg_Top4(val) ;
    //SevSeg_Set4DecU(--val);
  }
  if (PIFJ_PIFJ0)
  {
    PIFJ_PIFJ0 = 1;
    val = val == 9999 ? 0 : val + 1;
    //SevSeg_Top4(val) ;
  }
  SevSeg_Top4(val);
}
void PTJStart(void)
{
  //PPSJ_PPSJ0 = 1; //interupt on rising ie when pressed
  PIEJ = 0x03;
}