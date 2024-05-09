#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int ft_putstr(const char *str)
{
    int index;
    int ret;

    if (!str)
        return (0);
    index = 0;
    ret = 0;
    while (str[index])
    {
        ret += ft_putchr(str[index]);
        index++;
    }
    return (ret);
}

int main (int ac, char **av)
{
    if (ac != 2)
        return (0);
    char *s = av[1];
    ft_putstr(s);
    return (0);
}