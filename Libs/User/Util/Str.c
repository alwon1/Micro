#include <stdtypes.h>
#define bset(bit) (1 << (bit))
#define bclr(val, bit) ((val) & ~(1 << (bit)))

#define ESC #\x1b

Bool Char_is_Upper(char c)
{
	//feeling lazy
	return c >= 'A' && c <= 'Z' ? TRUE : FALSE;
}

Bool Char_is_Lower(char c)
{
	//feeling lazy
	return c >= 'a' && c <= 'z' ? TRUE : FALSE;
}

char Char_To_Upper(char c)
{
	return bclr(c, 6);
}

char Char_To_Lower(char c)
{
	return bset(6) | c;
}