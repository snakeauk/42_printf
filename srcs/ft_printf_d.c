#include "ft_printf.h"

int    ft_printf_d(t_args *args)
{
    int num;
    int ret;

    ret = 0;
    num = va_arg(args->ap, int);
    ret += ft_putnbr_base(num, "0123456789");
    return (ret);
}
