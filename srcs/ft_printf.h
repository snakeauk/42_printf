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
    size_t  index;
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
void    ft_print_format(t_format *f_fmt);
void	ft_init(t_format *f_fmt);
void	ft_printf_start(t_format f_fmt, const char *format);
void    ft_printf_type(t_format *f_fmt);
char	*ft_itoa_base(int n, int base);
int     ft_putstr(const char *str);
int     ft_putchr(const char c);
void    ft_printf_c(t_format *f_fmt);
void    ft_printf_s(t_format *f_fmt);
void    ft_printf_p(t_format *f_fmt);
void    ft_printf_d(t_format *f_fmt);
void    ft_printf_i(t_format *f_fmt);
void    ft_printf_u(t_format *f_fmt);
void    ft_printf_x(t_format *f_fmt);
void    ft_printf_large_x(t_format *f_fmt);
void    ft_print_percent(t_format *f_fmt);

#endif
