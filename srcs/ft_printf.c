#include "ft_printf.h"

void	ft_init(t_format *f_fmt)
{
	f_fmt->length = 0;
}

void	ft_print(t_format f_fmt, const char *format)
{
    f_fmt->string = format;	
    if (ft_strchr(f_fmt->string, '%'))
    {
        ft_putstr(f_fmt->string);
        f_fmt->length = ft_strlen(f_fmt->string);
    }
    ft_putstr(f_fmt);
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
