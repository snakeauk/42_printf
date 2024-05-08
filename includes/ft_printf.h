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
void	ft_print(t_format f_fmt, const char *format);
int	    ft_atoi(const char *str);
int     ft_isdigit(int c);
int     ft_isspace(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlen(const char *s);
int     ft_putchr(const char c);
int     ft_putstr(const char *str);

#endif
