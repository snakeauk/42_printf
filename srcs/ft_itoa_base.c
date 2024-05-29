#include "ft_printf.h"

char *ft_itoa_base(int n, char *base)
{
    long long ln;
    char *str;
    size_t size;

    ln = n;
    size = ft_size(n, (int)ft_strlen(base));
    str = (char *)malloc((size + 1) * sizeof(char));
    if (!str)
        return (NULL);
    str[size--] = '\0';
    if (ln < 0)
    {
        ln *= -1;
        str[0] = '-';
    }
    if (ln == 0)
        str[0] = '0';
    while (ln > 0)
    {
        str[size--] = base[ln % (int)ft_strlen(base)];
        ln /= (int)ft_strlen(base);
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
