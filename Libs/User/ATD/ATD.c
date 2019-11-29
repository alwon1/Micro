#include "ATD.h"
#include "Timer.h"
#include "derivative.h"
#include <hidef.h>
void ATD_Init(void)
{
    Timer_Init8us();
    DDR1AD0 = 0;
    ATD0CTL2 = ATD0CTL2_ADPU_MASK | ATD0CTL2_AFFC | ATD0CTL2_AWAI;
    Sleep_ms(1);                   //only need 50us but am lazy
    ATD0CTL3 = ATD0CTL3_FRZ1_MASK; //finish conversion before freezing
    ATD0CTL45_PRS = 6;
    ATD0CTL45_SMP = 1;
    ATD0CTL5 = ATD0CTL5_DJM_MASK | ATD0CTL5_SCAN_MASK | ATD0CTL5_MULT_MASK;
    return;
}
unsigned int ATD_Read(void)
{
    while (!ATD0STAT0_SCF)
        ;
    return ATD0DR0;
}