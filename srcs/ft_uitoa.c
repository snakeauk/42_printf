
#include "ft_printf.h"

char	*ft_uitoa_base(unsigned int n, char *base)
{
	char				*ret;
	size_t				size;
	size_t				base_len;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_uisize(n, base);
	base_len = ft_strlen(base);
	if ((ret = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ret[size] = '\0';
	while (size > 0)
	{
		ret[--size] = base[n % base_len];
		n /= base_len;
	}
	return (ret);
}
