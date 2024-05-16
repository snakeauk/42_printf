#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

#define BASE "0123456789ABCDEF"

typedef struct  s_args  
{
    va_list ap;
    char    *fmt;
    size_t  index;
    int     length;
    int     digit;
    int     base;
    int     minus_flag;
    int     plus_flag;
    int     space_flag;
    int     sharp_flag;
    int     comma_flag;
    int     asterisk_flag;
    int     width_flag;
    int     precision_flag;
    int     hh_flag;
    int     h_flag;
    int     l_flag;
    int     ll_flag;
    int     j_flag;
    int     z_flag;
    int     t_flag;
    int     error_flag;
}   t_args;

int     ft_printf(const char *format, ...);
void    ft_init(t_args *args);
void    ft_printf_flag(t_args *args);
void    ft_printf_width(t_args *args);
void    ft_printf_precision(t_args *args);
void    ft_printf_modifier(t_args *args);
char	*ft_itoa_base(int n, int base);
void    ft_printf_s(t_args *args);
void    ft_printf_p(t_args *args);
void    ft_printf_d(t_args *args);
void    ft_printf_i(t_args *args);
void    ft_printf_u(t_args *args);
void    ft_printf_x(t_args *args);
void    ft_printf_large_x(t_args *args);
void    ft_printf_percent(t_args *args);
int     ft_outchar(char c);

#endif

