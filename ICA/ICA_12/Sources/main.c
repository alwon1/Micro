#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */
//#define interrupt
//#define VectorNumber_Vsci0
#include "Delay.h"
#include "LCD.h"
#include "SCI0.h"
#include "7Seg.h"
void _Vsci0_RxItr(void);
void SlowTxt(char *);
void PTJStart(void);
char *strl = "Tell me A story.";
//this is now 13 an extension
void main(void)
{
  /* put your own code here */
  LCD_Init();
  _DISABLE_COP();
  SCI0_Init19200();
  SevSeg_Init();
  EnableInterrupts;
  PTJStart();
  SCI0CR2_RIE = 1;
  SevSeg_Top4(0);
  for (;;)
  {
    SlowTxt(strl);
    //_FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

interrupt VectorNumber_Vsci0 void _Vsci0_RxItr(void)
{
  char temp;
  if (SCI0SR1_RDRF)
  {
    temp = SCI0DRL;
    SCI0DRL = temp;
  }
  return;
}
void SlowTxt(char *str)
{
  char x = 0, row = 0;
  LCD_Init();
  LCD_Pos(0, 0);
  x = 0;
  do
  {
    Delay_C(200);
   // if (str[x] == '\n')
     // LCD_Pos(++row, 0);
    //else
      LCD_Char(str[x++]);
  } while (str[x]);
}
interrupt VectorNumber_Vportj void PJInterupt(void)
{
  static unsigned int val =0;
  if(PIFJ_PIFJ0)
  {
    PIFJ_PIFJ0 = 1;
    val = val<9999? val-1:9999;
    SevSeg_Top4(val) ;
  //SevSeg_Set4DecU(--val);
  }
  if (PIFJ_PIFJ1)
  {
    PIFJ_PIFJ1 =1;
    val = val<9999? val+1:9999;
   SevSeg_Top4(val) ;
  }
  
  
}
void PTJStart(void)
{
  PIEJ = 0x03;
}