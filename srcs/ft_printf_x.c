#include "ft_printf.h"

int     ft_printf_x(t_args *args)
{
    int             ret;
    unsigned int    num;

    ret = 0;
    num = va_arg(args->ap, unsigned long long);
    ret += ft_putunbr_base(num, BASE_LOW_16);
    return (ret);
}
