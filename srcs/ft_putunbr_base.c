#include "ft_printf.h"

int ft_putunbr_base(unsigned long long num, char *base)
{
    int                 ret;
    unsigned long long  base_len;
    
    ret = 0;
    base_len = (unsigned long long)ft_strlen(base);
    if (num >= base_len)
        ret += ft_putunbr_base(num / base_len, base);
    ret += ft_outchar(base[num % base_len]);
    return(ret);
}
// #include <stdio.h>
// int main(int ac, char **av)
// {
//     if (ac != 2)
//         return (0);
//     int num = ft_atoi(av[1]);
//     printf("ft_putunbr_base:%d", ft_putunbr_base(num, "0123456789abcdef"));
//     return(0);
// }