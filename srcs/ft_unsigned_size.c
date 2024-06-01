#include "ft_printf.h"

size_t	ft_unsigned_size(unsigned long long uln, int base)
{
	size_t	size;

	size = 1;
	if (uln < 0)
	{
		size++;
		uln *= -1;
	}
	while (uln >= base)
	{
		size++;
		uln /= base;
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
