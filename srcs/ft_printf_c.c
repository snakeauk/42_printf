#include "ft_printf.h"

int ft_printf_c(t_args *args)
{
    int     ret;
    char    c;

    ret = 0;
    c = va_arg(args->ap, int);
    ret += ft_outchar(c);
    if (ret == -1)
        args->error_flag++;
    return (ret);
}
