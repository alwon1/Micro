#ifndef l
#define l
void Delay_C(int mSec) 
{
  asm ldx mSec
  asm Delay:    ldy   #2665
  asm delay_2:  dbne  y, delay_2
  asm dbne      x,    Delay  
  return;
}
//~ 20us
void Short_Delay(void) 
{
  asm ldy       #10
  asm dbne      y,    *
  return;
}
//Delay of 49.2ms
void Long_Delay(void) 
{
  asm ldy       #0
  asm dbne      y,    *
  return;
}
#endif
  