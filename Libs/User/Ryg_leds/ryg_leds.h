#ifndef RYG_LEDS_H
#define RYG_LEDS_H
typedef enum
{
	Red = 0x80,
	Yellow = 0x40,
	Green = 0x20
} rygLed_t;
void Ryg_Init(void);

void Ryg_All_On(void);
void Ryg_All_Off(void);

void Ryg_Sel_On(rygLed_t Leds);
void Ryg_Sel_Off(rygLed_t Leds);

void Ryg_Tog(rygLed_t Leds);
void Ryg_Set(rygLed_t Leds);
rygLed_t Ryg_Status(void);

#endif