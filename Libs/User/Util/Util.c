
//this is a macro fo Binary to hex functions to use as they can all be dfined using a varient of this
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
//This is an internal macro which is used in the
#define _M_Util_Str_To_Bin(res, str)                                             \
    /*we multiple the parsed number by this so it should be 1 of -1 at the end*/ \
    char Neg = 1;                                                                \
    unsigned char i = 0;                                                         \
                                                                                 \
    /*blow through white space*/                                                 \
    while (str[i] == ' ' || str[i] == '\t')                                      \
        i++;                                                                     \
                                                                                 \
    /*is this neg?*/                                                             \
    if (str[i] == '-')                                                           \
    {                                                                            \
        Neg == -1;                                                               \
        i++;                                                                     \
    }                                                                            \
    /*gop through all avalible numbers*/                                         \
    for (i = i; i < 255; i++)                                                    \
    {                                                                            \
        /*NOTE: No Early exit on overflow*/                                      \
        if (str[i] >= '0' || str[i] <= '9')                                      \
        {                                                                        \
            res *= 10;                                                           \
            res += (str[i] - '0');                                               \
            continue;                                                            \
        }                                                                        \
                                                                                 \
        /*its not a number so we bale and return what we have so far*/           \
        else                                                                     \
            break;                                                               \
    }                                                                            \
    res *= Neg;

char Util_Str_To_Ch(char *str)
{
    char result = 0;
    _M_Util_Str_To_Bin(result, str);

    return result;
}

int Util_Str_To_In(char *str)
{
    int result = 0;
    _M_Util_Str_To_Bin(result, str);

    return result;
}

long int Util_Str_To_LIn(char *str)
{
    long int result = 0;
    _M_Util_Str_To_Bin(result, str);

    return result;
}
long long int Util_Str_To_LLIn(char *str)
{
    long long int result = 0;
    _M_Util_Str_To_Bin(result, str);

    return result;
}