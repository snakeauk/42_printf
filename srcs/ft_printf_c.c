#include "ft_printf.h"

int ft_printf_c(t_args *args)
{
    int     ret;
    char    c;

    ret = 0;
    c = va_arg(args->ap, int);
    if (!ft_isascii(c))
    {
        args->error_flag++;
        ret++;
        return (ret);
    }
    ret += ft_outchar(c);
    return (ret);
}