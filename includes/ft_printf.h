#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define BASE_10 "0123456789"
#define BASE_LOW_16 "0123456789abcdef"
#define BASE_TOP_16 "0123456789ABCDEF"

typedef struct  s_args  
{
    va_list ap;
    char    *fmt;
    size_t  index;
    int     length;
    int     digit;
    int     minus_flag;
    int     plus_flag;
    int     space_flag;
    int     sharp_flag;
    int     zero_flag;
    int     comma_flag;
    int     asterisk_flag;
    int     dot_flag;
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
void    ft_vprintf(t_args *args);
int     ft_outchar(char c);
int     ft_outstr(const char *str);
// void    ft_init(t_args *args);
// void    ft_printf_flags(t_args *args);
// void    ft_printf_width(t_args *args);
// void    ft_printf_precision(t_args *args);
void    ft_printf_type(t_args *args);
int     ft_printf_c(t_args *args);
int     ft_printf_s(t_args *args);
int     ft_printf_p(t_args *args);
int     ft_printf_d(t_args *args);
int     ft_printf_i(t_args *args);
int     ft_printf_u(t_args *args);
int     ft_printf_x(t_args *args);
int     ft_printf_large_x(t_args *args);
int     ft_putnbr_base(long long num, char *base);
int     ft_putunbr_base(unsigned long long num, char *base);

#endif