#include "ft_printf.h"

int     ft_printf_p(t_args *args)
{
    int                 ret;
    unsigned long long  num;

    ret = 0;
    num = va_arg(args->ap, unsigned long long);
    ret += ft_outstr("0x");
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