#include "ft_printf.h"

int ft_putstr(const char *str)
{
    int index;

    if (!str)
        return (0);
    index = 0;
    while (str[index])
    {
        ft_putchr(&str[index]);
        index++;
    }
    return (index);
}
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main (int ac, char **av)
{
    if (ac != 2)
        return (0);
    ft_putstr(av[1]);
    return (0);
}