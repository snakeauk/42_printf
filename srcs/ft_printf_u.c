#include "ft_printf.h"

int    ft_printf_u(t_args *args)
{
    int num;
    int ret;
    char *str;

    ret = 0;
    num = va_arg(args->ap, int);
    if (!num)
    {
        args->error_flag++;
        return (ret);
    }
    str = ft_itoa_base(num, 16);
    ret += ft_outstr(str);
    return (ret);
}
