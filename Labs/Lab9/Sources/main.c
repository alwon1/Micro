#include "I2C.h"
#include "LCD.h"
//#include "Timer.h"
#include "delay.h"
#include "derivative.h" /* derivative-specific definitions */
#include <hidef.h>      /* common defines and macros */
#include <stdio.h>
void init(void);
char temp(void);
void main(void)
{
  /* put your own code here */
  char x, y, z;
  char buff[255];
  IIC0_Init();
  LCD_Init();
  init();
  //EnableInterrupts;

  for (;;)
  {
    LCD_Pos(0, 0);
    sprintf(buff, "%d", temp());
    LCD_String(buff);
    Delay_C(100);
    //Sleep_ms(100);
    //_FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
void init(void)
{
  char x;
  //
  IIC0_Addr(0x60, 0, 1, 1);
  IIC0_WriteByte(0x26, 1);
  IIC0_WriteByte(0x38, 1);
  //
  IIC0_Addr(0x60, 0, 1, 1);
  IIC0_WriteByte(0x13, 1);
  IIC0_WriteByte(0x07, 1);
  //
  IIC0_Addr(0x60, 0, 1, 1);
  IIC0_WriteByte(0x26, 1);
  IIC0_WriteByte(0x39, 1);
  //

  do
  {
    IIC0_Addr(0x60, 0, 1, 1);
    IIC0_WriteByte(0x00, 1);
    IIC0_Addr(0x60, 1, 1, 1);
    IIC0_ReadByte(&x, 1, 1);
  } while (!(x & 0x02));
  return;
}
char temp(void)
{
  char x;
  IIC0_Addr(0x60, 0, 0, 1);
  IIC0_WriteByte(0x04, 0);
  IIC0_Addr(0x60, 1, 1, 1);

  IIC0_ReadByte(&x, 1, 1);
  return x;
}
