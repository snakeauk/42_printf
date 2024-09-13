#include "ft_printf.h"

size_t	ft_uisize(unsigned int n, char *base)
{
	size_t		base_len;
	size_t		size;

	base_len = ft_strlen(base);
	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		size++;
		n /= base_len;
	}
	return (size);
}