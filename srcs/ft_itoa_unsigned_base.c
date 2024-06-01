#include "ft_printf.h"

char *ft_itoa_unsigned_base(unsigned long long uln, char *base)
{
    char *str;
    size_t size;

    size = ft_unsigned_size(uln, (int)ft_strlen(base));
    str = (char *)malloc((size + 1) * sizeof(char));
    if (!str)
        return (NULL);
    str[size--] = '\0';
    if (uln < 0)
    {
        uln *= -1;
        str[0] = '-';
    }
    if (uln == 0)
        str[0] = '0';
    while (uln > 0)
    {
        str[size--] = base[uln % (int)ft_strlen(base)];
        uln /= (int)ft_strlen(base);
    }
    return (str);
}
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main(int ac, char **av)
// {
//     if (ac != 3)
//         return (0);
//     int n = atoi(av[1]);
//     char *base = av[2];
//     printf("%s", ft_itoa_base(n, base));
//     return (0);
// }