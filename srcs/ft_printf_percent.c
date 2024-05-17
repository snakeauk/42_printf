#include "ft_printf.h"

int    ft_printf_percent(t_args *args)
{
    int ret;

    ret = 0;
    ret += ft_putchar('%');
    return (ret);
}