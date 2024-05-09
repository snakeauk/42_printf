#ifndef 	FT_PRINTF_H
# define	FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_format
{
	va_list	args;
    char    string;
    char    fmt;
	int		length;
    int     width;
    int     digit;
    int     base;
    int     negative;
    int     asterisk_flag;
    int     dot_flag;
    int     error_flag;
    int     index_flag;
}	t_format;

int		ft_printf(const char *, ...);
void	ft_init(t_format *f_fmt);
void	ft_printf_start(t_format f_fmt, const char *format);
char	*ft_itoa_base(int n, int base);
int     ft_putstr(const char *str);
int     ft_putchr(const char c);

#endif
