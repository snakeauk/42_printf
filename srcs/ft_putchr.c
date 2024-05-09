#include "ft_printf.h"

int ft_putchr(const char c)
{
    write(1, &c, 1);
    return (1);
}
