//Hitachi 44780 initialization and commands
//Processor:  MC9S12XDP512
//Crystal:  16 MHz
//by P Ross Taylor
//May 2015

void LCD_Init(void);			//8-bit, 2-line, 5x8 chars, disp on, curs on, blink off, inc curs mode, no shift, clear, home
void LCD_Ctrl(unsigned char ctl);
unsigned char LCD_Busy(void);
void LCD_Char(unsigned char);
void LCD_Addr(unsigned char addr);	//raw LCD DDRAM address -- requires knowledge of device
void LCD_Pos(unsigned char Row,unsigned char Col);	//Row and Column, zero based; out of range values go to home location
void LCD_String(char *);		//requires a NULL-terminated string of ASCII characters in main program
