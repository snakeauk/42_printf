#include "ft_printf.h"

int ft_printf_c(t_args *args)
{
    int     ret;
    char    c;

    ret = 0;
    c = va_arg(args->ap, char);
    if (!c)
    {
        args->error_flag++;
        return (ret);
    }
    ret += ft_outchar(c);
    return (ret);
}