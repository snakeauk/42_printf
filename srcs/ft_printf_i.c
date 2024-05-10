#include "ft_printf.h"

void    ft_printf_i(t_format *f_fmt)
{
    int     num;
    char    *int_str;

    f_fmt->base = 10;
    num = va_arg(f_fmt->args, int);
    int_str = ft_itoa_base(num, f_fmt->base);
    f_fmt->length += ft_strlen(int_str);
    ft_putstr(int_str);
}
