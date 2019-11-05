//Seven Segment Display Controller Library
//Processor:  MC9S12XDP512
//Crystal:  16 MHz
//by P Ross Taylor
//June 2015

void SevSeg_Init(void);
void SevSeg_Char(unsigned char, unsigned char);		//character and digit address
void SevSeg_BlChar(unsigned char);					//digit address
void SevSeg_BlAll(void);
void SevSeg_dChar(unsigned char, unsigned char);	//character and digit address
void SevSeg_Top4(unsigned int);						//four chars compressed as four nibbles in an int
void SevSeg_Bot4(unsigned int);						//four chars compressed as four nibbles in an int
void SevSeg_Cust(unsigned char, unsigned char);		//selected segments and digit address



