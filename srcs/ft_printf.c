#include "ft_printf.h"

void	ft_init(t_format *f_fmt)
{
	f_fmt->length = 0;
}

void	ft_print(t_format f_fmt, const char *format)
{
	
}

int		ft_printf(const char *format, ...)
{
	t_format	*f_fmt;
	if (!format)
		return (-1);
	f_fmt = (t_format *)malloc(sizeof(t_format));
	if (!f_fmt)
		return (-1);
	ft_init(f_fmt);
	if (*format)
	{
		va_start(f_fmt->args, format);
		ft_print(f_fmt, format);
		va_end(f_fmt->args);
	}
	free(f_fmt);
	return (f_fmt->length);
}