#include "ft_printf.h"

int ft_outstr(const char *str)
{
    size_t  index;
    int     ret;

    ret = 0;
    index = 0;
    if (!str)
        return (ret);
    while (str[index])
    {
        ret += ft_outchar(str[index]);
        index++;
    }
    return (ret);
}
// #include <stdio.h>
// int main(int ac, char **av)
// {
//     if (ac != 2)
//         return (0);
//     printf("\nreturn:%d", ft_outstr(av[1]));
//     return (0);
// }