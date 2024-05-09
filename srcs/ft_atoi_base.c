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
    char            *base_num;
	size_t			size;

	ln = n;
	size = ft_size(n, base);
    base_num = "0123456789ABCDEF";
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
        if (ln % base < 10)
		    str[size--] = (ln % base) + '0';
        else
            str[size--] = ((ln % base) - 10) + 'A';
		ln /= base;
	}
	return (str);
}
