
//this is a macro fo Binary to hex functions to use as they can all be dfined using a varient of this
#define _M_Util_Binary_To_BCD(val, res)                  \
    char i;                                              \
    result = val % 10;                                   \
    for (i = 1; i < sizeof(val) * 2; i++)                \
    {                                                    \
        result += ((val / (10 * (10* i)) % 10) << 4 * i; \
    }

unsigned int Util_Binary_To_BCD_uI(unsigned int val)
{
    unsigned int result;
    result = val % 10;
    result += ((val / 10) % 10) << 4;
    result += ((val / 100) % 10) << 8;
    result += ((val / 1000) % 10) << 12;
    return result;
}

/* unsigned int Util_Binary_To_BCD_uI(unsigned int val)
{
    unsigned int result;
    _M_Util_Binary_To_BCD(val, result);
    return result;
}
 */
unsigned char Util_Binary_To_BCD_uC(unsigned char val)
{
    unsigned char result;
    //  _M_Util_Binary_To_BCD(val, result);
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
char Util_ch_To_Ch(char ch)
{
    //char result = 0;
    if (ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }

    return 0xff;
}

int Util_Str_To_In(char *str)
{
    int result = 0;
    char Neg = 1;
    unsigned char i = 0;

        /*blow through white space*/
    while (str[i] == ' ' || str[i] == '\t')
        i++;

            /*is this neg?*/
    if (str[i] == '-')
    {
        Neg = -1;
        i++;
    } /*gop through all avalible numbers*/
    for (i = i; i < 255; i++)
    { /*NOTE: No Early exit on overflow*/
        if (str[i] >= '0' && str[i] <= '9')
        {
            result *= 10;
            result += (str[i] - '0');
            continue;
        }

        /*its not a number so we bale and return what we have so far*/
        else
            break;
    }
    result *= Neg;

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