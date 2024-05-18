#include "ft_printf.h"

int    ft_printf_d(t_args *args)
{
    int num;
    int ret;
    char *str;

    ret = 0;
    num = va_arg(args->ap, int);
    if (!num)
    {
        args->error_flag++;
        ret++;
        return (ret);
    }
    str = ft_itoa_base(num, 10);
    if (!str)
    {
        args->error_flag++;
        ret++;
        return (ret);
    }
    ret += ft_outstr(str);
    free(str);
    return (ret);
}
