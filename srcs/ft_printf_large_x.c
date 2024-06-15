#include "ft_printf.h"

int     ft_printf_large_x(t_args *args)
{
    int             ret;
    unsigned int    num;

    ret = 0;
    num = va_arg(args->ap, unsigned long long);
    ret += ft_putunbr_base(num, "0123456789ABCDEF");
    return (ret);
}
