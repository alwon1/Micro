
typedef enum
{
    PWM0_RGB_B = 0,
    PWM1_RGB_G,
    PWM2,
    PWM3_LCD_BK,
    PWM4_RGB_R,
    PWM5,
    PWM6_SPK,
    PWM7
} PWM_Channel;
void PWM_Init(void);
void PWM_SetFrequency(PWM_Channel channel, unsigned long frequency);
void PWM_SetDutyHalfCh(PWM_Channel channel, unsigned char duty);
void PWM_SetDutyHalf(PWM_Channel channel, float duty);