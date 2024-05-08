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
