#include "ft_printf.h"

size_t	ft_size(int n, int base)
{
	size_t	size;
    long long num;

    num = n;
	size = 1;
	if (num < 0)
	{
		size++;
		num *= -1;
	}
	while (num >= base)
	{
		size++;
		num /= base;
	}
	return (size);
}
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main(int ac, char **av)
// {
//     if (ac != 2)
//         return (0);
//     printf("%d", ft_size(atoi(av[1]), 10));
//     return (0);
// }
