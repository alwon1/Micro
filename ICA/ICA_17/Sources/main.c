#include "ATD.h"
#include "LCD.h"
#include "Timer.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */
#include <stdio.h>

char buff[100];

void main(void)
{
  float val = 0;
  /* put your own code here */
  LCD_Init();
  Timer_Init8us();
  ATD_Init();

  //EnableInterrupts;

  for (;;)
  {
    sprintf(buff, "Voltage = %5.3f V", (((float)ATD_Read()) / 200));
    LCD_Pos(0,0);
    LCD_String(buff);
    Sleep_ms(2550);
    //_FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
