#include "ft_printf.h"

int ft_printf_s(t_args *args)
{
    char    *str;
    int ret;
    char *str;

    ret = 0;
    str = va_arg(args->ap, char *);
    if (!str)
    {
        args->error_flag++;
        return (ret);
    }
    ret += ft_outstr(str);
    return (ret);
}
