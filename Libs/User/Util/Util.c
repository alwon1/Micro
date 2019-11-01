unsigned long int Util_Binary_To_BCD(unsigned long int val)
{
    unsigned long int result;
    char i;
    for ( i = 0; i < 8; i++)
    {
        result += (val%10)<<i*4;
    }
    
}