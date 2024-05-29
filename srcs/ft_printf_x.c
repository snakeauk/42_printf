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
    str = ft_itoa_base(num, "0123456789abcdef");
    while (str[index])
    {
        str[index] = ft_tolower(str[index]);
        index++;
    }
    ret += ft_outstr(str);
    free(str);
    return (ret);
}
