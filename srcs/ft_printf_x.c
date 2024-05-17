#include "ft_printf.h"

int    ft_printf_x(t_args *args)
{
    int     ret;
    int     num;
    size_t  index;
    char    *str;

    ret = 0;
    index = 0;
    num = va_arg(args->ap, int);
    if (!num)
    {
        args->error_flag++;
        return (ret);
    }
    str = ft_atoi_base(num, 16);
    while (str[index])
    {
        str[index] = ft_tolower(str[index]);
        index++;
    }
    ret += ft_outstr(str);
    return (ret);
}
