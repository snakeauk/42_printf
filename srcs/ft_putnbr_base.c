#include "ft_printf.h"

int ft_putnbr_base(long long num, char *base)
{
    int         ret;
    long long   base_len;

    ret = 0;
    base_len = (long long)ft_strlen(base);
    if (num < 0)
    {
        ret += ft_outchar('-');
        num *= -1;
    }
    if (num >= base_len)
        ret += ft_putnbr_base(num / base_len, base);
    ret += ft_outchar(base[num % base_len]);
    return(ret);
}
