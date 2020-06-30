#ifndef l
#define l
void Delay_C(int mSec) 
{
  __asm("$1");
  __asm("$1");
  __asm("$1");
  __asm("$1");
  return;
}
//~ 20us
void Short_Delay(void) 
{
  __asm("$1");
  __asm("$1");
  return;
}
//Delay of 49.2ms
void Long_Delay(void) 
{
  __asm("$1");
  __asm("$1");
  return;
}
#endif
  