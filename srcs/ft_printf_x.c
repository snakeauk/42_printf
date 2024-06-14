#include "ft_printf.h"

// int    ft_printf_x(t_args *args)
// {
//     int                 ret;
//     unsigned long long  ulnum;
//     char                *str;

//     ret = 0;
//     ulnum = va_arg(args->ap, unsigned long long);
//     str = ft_itoa_unsigned_base(ulnum, "0123456789abcdef");
//     ret += ft_outstr(str);
//     free(str);
//     return (ret);
// }
int     ft_printf_x(t_args *args)
{
    int             ret;
    unsigned int    num;

    ret = 0;
    num = va_arg(args->ap, unsigned long long);
    ret += ft_putunbr_base(num, "0123456789abcdef");
    return (ret);
}
// #include <stdio.h>
// int main(int ac, char **av)
// {
//     if (ac != 2)
//         return (0);
//     unsigned long long num = ft_atoi(av[1]);
//     printf("\nft_putnbr_p:%d", ft_putnbr_p(num, "0123456789abcdef"));
//     return (0);
// }