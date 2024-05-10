#include "ft_printf.h"

static size_t	ft_size(int n, int base)
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

char	*ft_itoa_base(int n, int base)
{
	long long	ln;
	char			*str;
	size_t			size;

	ln = n;
	size = ft_size(n, base);
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
		str[size--] = "0123456789ABCDEF"[ln % base];
		ln /= base;
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
//     int base = atoi(av[2]);
//     printf("%s", ft_itoa_base(n, base));
//     return (0);
// }
