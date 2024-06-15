#include "ft_printf.h"

int     ft_printf_u(t_args *args)
{
    int             ret;
    unsigned int    num;

    ret = 0;
    num = va_arg(args->ap, unsigned int);
    ret = ft_putunbr_base(num, "0123456789");
    return (ret);
}