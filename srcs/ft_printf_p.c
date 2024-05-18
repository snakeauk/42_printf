#include "ft_printf.h"

int    ft_printf_p(t_args *args)
{
    int     num;
    int     ret;
    char    *str;

    ret = 0;
    num = va_arg(args->ap, int);
    if (!num)
    {
        args->error_flag++;
        return (ret);
    }
    str = ft_itoa_base(num, 16);
    if (!str)
    {
        args->error_flag++;
        return (ret);
    }
    ret += ft_outstr(str);
    return (ret);
}
