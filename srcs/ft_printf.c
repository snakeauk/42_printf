#include "ft_printf.h"

void	ft_init(t_format *f_fmt)
{

}

void    ft_printf_flag(t_format *f_fmt, int *index)
{
    if (f_fmt->string[index] == '0' && f_fmt->string[&index + 1] == '-')
        *index++;
    if ((f_fmt->flag_index = f_strchr(f_fmt->flag, f_fmt->string[*index]) >= 0))
        *index++;
    if (tab->string[*index] == '*')
    {
        *index++;
        f_fmt->astarisk = 1;
    }
    if (ft_isdigit(f_fmt->string[index]))
        f_fmt->width = ft_atoi(&f_fmt->string[*index], &*index);
    if (f_fmt->string[*index] == '.')
    {
        *index++;
        f_fmt->dot = 1;
        f_fmt->width = ft_atoi(&f_fmt->string[*index], &*index);
    }
    if (f_fmt->string[*index] == '*')
    {
        *index++;
        f_fmt->astarisk = 1;
    }
}

void    ft_printf_format(t_format *f_fmt)
{
    int index;

    index = 0;
    while (f_fmt->string[i])
    {
        if (f_fmt->string[index] == '%')
        {
            index++;
            ft_printf_flag(f_fmt, &index);
        }
        else
        {
            write(1, &f_fmt->string[index], 1);
            f_fmt->length++;
        }
        ft_init(f_fmt);
        index++;
    }
}

void	ft_print(t_format f_fmt, const char *format)
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
