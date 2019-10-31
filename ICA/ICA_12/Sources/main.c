#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */
//#define interrupt
//#define VectorNumber_Vsci0
#include "Delay.h"
#include "LCD.h"
#include "SCI0.h"
void _Vsci0_RxItr(void);
void SlowTxt(char *);
char *strl = "Tell me A story.";
void main(void)
{
  /* put your own code here */
  LCD_Init();
  _DISABLE_COP();
  SCI0_Init19200();
  EnableInterrupts;
  SCI0CR2_RIE = 1;
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