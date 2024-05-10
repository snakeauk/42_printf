#include "ft_printf.h"

void	ft_init(t_format *f_fmt)
{
    f_fmt->width = 0;
    f_fmt->fmt = 0;
    f_fmt->digit = 0;
    f_fmt->base = 0;
    f_fmt->negative = 0;
    f_fmt->asterisk_flag = 0;
    f_fmt->dot_flag = 0;
    f_fmt->error_flag = 0;
    f_fmt->index_flag = 0;
}

void    ft_printf_flag(t_format *f_fmt)
{
    if (f_fmt->string[f_fmt->index] == '0' && f_fmt->string[&f_fmt->index + 1] == '-')
        *f_fmt->index++;
    if ((f_fmt->index_flag = f_strchr(f_fmt->index_flag, f_fmt->string[*f_fmt->index]) >= 0))
        *f_fmt->index++;
    if (f_fmt->string[*f_fmt->index] == '*')
    {
        *f_fmt->index++;
        f_fmt->asterisk_flag++;
    }
    if (ft_isdigit(f_fmt->string[f_fmt->index]))
        f_fmt->width = ft_atoi(&f_fmt->string[*f_fmt->index]);
    if (f_fmt->string[*f_fmt->index] == '.')
    {
        *f_fmt->index++;
        f_fmt->dot_flag++;
        f_fmt->width = ft_atoi(&f_fmt->string[*f_fmt->index], &*f_fmt->index);
    }
    if (f_fmt->string[*f_fmt->index] == '*')
    {
        *f_fmt->index++;
        f_fmt->asterisk_flag++;
    }
}

void    ft_printf_type(t_format *f_fmt)
{
    if (f_fmt->string[f_fmt->index] == 'c')
        ft_printf_c(f_fmt);
    else if (f_fmt->string[f_fmt->index] == 's')
        ft_printf_s(f_fmt);
    else if (f_fmt->string[f_fmt->index] == 'p')
        ft_printf_p(f_fmt);
    else if (f_fmt->string[f_fmt->index] == 'd')
        ft_printf_d(f_fmt);
    else if (f_fmt->string[f_fmt->index] == 'i')
        ft_printf_i(f_fmt);
    else if (f_fmt->string[f_fmt->index] == 'u')
        ft_printf_u(f_fmt);
    else if (f_fmt->string[f_fmt->index] == 'x')
        ft_printf_x(f_fmt);
    else if (f_fmt->string[f_fmt->index] == 'X')
        ft_printf_X(f_fmt);
    else if (f_fmt->string[f_fmt->index] == '%')
        ft_print_percent(f_fmt);
    else if (f_fmt->width > 0)
        f_fmt->error_flag = 1;
}

void    ft_print_format(t_format *f_fmt)
{
    while (f_fmt->string[f_fmt->index])
    {
        if (f_fmt->string[f_fmt->index] == '%')
        {
            f_fmt->index++;
            ft_printf_flag(f_fmt);
            ft_put_fmt(f_fmt);
            ft_printf_type(f_fmt);
        }
        else
        {
            ft_putchr(f_fmt->string[f_fmt->index]);
            f_fmt->length++;
        }
        ft_init(f_fmt);
        f_fmt->index++;
    }
}

void	ft_printf_start(t_format *f_fmt, const char *format)
{
    if (ft_strchr(f_fmt->string, '%'))
    {
        ft_putstr(f_fmt->string);
        f_fmt->length = ft_strlen(f_fmt->string);
    }
    ft_printf_format(f_fmt);
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
    f_fmt->length = 0;
    f_fmt->index = 0;
    f_fmt->string = format;
    va_start(f_fmt->args, format);
    ft_printf_start(f_fmt, format);
    va_end(f_fmt->args);
	free(f_fmt);
	return (f_fmt->length);
}
