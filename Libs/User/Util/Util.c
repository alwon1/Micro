

#define _M_Util_Binary_To_BCD(val, res)   \
    char i;                               \
    for (i = 0; i < sizeof(val) * 2; i++) \
    {                                     \
        result += (val % 10) << i * 4;    \
        val = val / 10;                   \
    }

unsigned long int Util_Binary_To_BCD_uLI(unsigned long int val)
{
    unsigned long int result;
    _M_Util_Binary_To_BCD(val, result);
    return result;
}

unsigned int Util_Binary_To_BCD_uI(unsigned int val)
{
    unsigned int result;
    _M_Util_Binary_To_BCD(val, result);
    return result;
}

unsigned char Util_Binary_To_BCD_uC(unsigned char val)
{
    unsigned char result;
    _M_Util_Binary_To_BCD(val, result);
    return result;
}
