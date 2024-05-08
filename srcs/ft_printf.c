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

void    ft_printf_flag(t_format *f_fmt, int *index)
{
    if (f_fmt->string[index] == '0' && f_fmt->string[&index + 1] == '-')
        *index++;
    if ((f_fmt->index_flag = f_strchr(f_fmt->index_flag, f_fmt->string[*index]) >= 0))
        *index++;
    if (f_fmt->string[*index] == '*')
    {
        *index++;
        f_fmt->asterisk_flag++;
    }
    if (ft_isdigit(f_fmt->string[index]))
        f_fmt->width = ft_atoi(&f_fmt->string[*index], &*index);
    if (f_fmt->string[*index] == '.')
    {
        *index++;
        f_fmt->dot_flag++;
        f_fmt->width = ft_atoi(&f_fmt->string[*index], &*index);
    }
    if (f_fmt->string[*index] == '*')
    {
        *index++;
        f_fmt->asterisk_flag++;
    }
}

void    ft_printf_precision(t_format *f_fmt, int index)
{
    if (f_fmt->string[index] == 'c')
        ft_printf_c(f_fmt);
    else if (f_fmt->string[index] == 's')
        ft_printf_s(f_fmt);
    else if (f_fmt->string[index] == 'p')
        ft_printf_p(f_fmt);
    else if (f_fmt->string[index] == 'd')
        ft_printf_d(f_fmt);
    else if (f_fmt->string[index] == 'i')
        ft_printf_i(f_fmt);
    else if (f_fmt->string[index] == 'u')
        ft_printf_u(f_fmt);
    else if (f_fmt->string[index] == 'x')
        ft_printf_x(f_fmt);
    else if (f_fmt->string[index] == 'X')
        ft_printf_X(f_fmt);
    else if (f_fmt->string[index] == '%')
        ft_print_percent(f_fmt);
    else if (f_fmt->width > 0)
        f_fmt->error_flag = 1;
}

void    ft_printf_format(t_format *f_fmt)
{
    size_t index;

    index = 0;
    while (f_fmt->string[index])
    {
        if (f_fmt->string[index] == '%')
        {
            index++;
            ft_printf_flag(f_fmt, &index);
            ft_put_fmt(f_fmt, index);
            ft_printf_precision(f_fmt, index);
        }
        else
        {
            ft_putchr(f_fmt->string[index]);
            f_fmt->length++;
        }
        ft_init(f_fmt);
        index++;
    }
}

void	ft_print(t_format *f_fmt, const char *format)
{
    f_fmt->string = format;	
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
    f_fmt->string = '\0';
	if (*format)
	{
		va_start(f_fmt->args, format);
		ft_print(f_fmt, format);
		va_end(f_fmt->args);
	}
	free(f_fmt);
	return (f_fmt->length);
}
