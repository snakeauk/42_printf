#ifndef 	FT_PRINTF_H
# define	FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_format
{
	va_list	args;
	int		length;
}	t_format;

int		ft_printf(const char *, ...);
void	ft_init(t_format *f_fmt);
void	ft_print(t_format f_fmt, const char *format);

#endif