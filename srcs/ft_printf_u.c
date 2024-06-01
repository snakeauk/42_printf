#include "ft_printf.h"

int    ft_printf_u(t_args *args)
{
    unsigned int num;
    int ret;
    char *str;

    ret = 0;
    num = va_arg(args->ap, unsigned long long);
    if (!num)
    {
        args->error_flag++;
        return (ret);
    }
    str = ft_itoa_unsigned_base(num, "0123456789ABCDEF");
    if (!str)
    {
        args->error_flag++;
        return (ret);
    }
    ret += ft_outstr(str);
    free(str);
    return (ret);
}
