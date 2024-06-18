#include "ft_printf.h"

int     ft_printf_p(t_args *args)
{
    int                 ret;
    unsigned long long  num;

    ret = 0;
    num = va_arg(args->ap, unsigned long long);
    ret += ft_outstr("0x");
    ret += ft_putunbr_base(num, BASE_LOW_16);
    return (ret);
}
