#include "ft_printf.h"

char    *ft_printf_int(int n, int base)
{
    char    *change_num;

    change_num = ft_itoa_base(n, base);
    ft_putstr(change_num);
}

void    ft_printf_d(t_format *f_fmt)
{
    int num;
    int base;
    char *s;

    f_fmt->base = 10;
    num = va_arg(f_fmt->arg, int);
    s = ft_printf_int(num, f_fmt->base);
}
