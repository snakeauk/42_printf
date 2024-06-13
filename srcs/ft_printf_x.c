#include "ft_printf.h"

int    ft_printf_x(t_args *args)
{
    int                 ret;
    unsigned long long  ulnum;
    size_t              index;
    char                *str;

    ret = 0;
    index = 0;
    ulnum = va_arg(args->ap, unsigned long long);
    str = ft_itoa_unsigned_base(ulnum, "0123456789abcdef");
    while (str[index])
    {
        str[index] = ft_tolower(str[index]);
        index++;
    }
    ret += ft_outstr(str);
    free(str);
    return (ret);
}
