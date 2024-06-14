#include "ft_printf.h"

// int ft_putnbr_u(unsigned int num)
// {
//     int ret;

//     ret = 0;
//     if (num >= 10)
//         ret += ft_putnbr_u(num / 10);
//     ret += ft_outchar('0' + num % 10);
//     return(ret);
// }

int     ft_printf_u(t_args *args)
{
    int             ret;
    unsigned int    num;

    ret = 0;
    num = va_arg(args->ap, unsigned int);
    ret = ft_putunbr_base(num, "0123456789");
    return (ret);
}
// #include <stdio.h>
// int main(int ac, char **av)
// {
//     if (ac != 2)
//         return (0);
//     unsigned int num = (unsigned int)ft_atoi(av[1]);
//     printf("ft_putnbr_u:%d", ft_putnbr_u(num));
//     return (0);
// }