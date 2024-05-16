#include "printf.h"

int    ft_outchar(const char c)
{
    if (!c)
        return (0);
    write(1, &c, 1);
    return (1);
}
// #include <stdio.h>
// int main(int ac, char **av)
// {
//     if (ac != 2)
//         return (0);
//     char c = av[1][0];
//     printf("%d", ft_outchar(c));
//     return (0);
// }
