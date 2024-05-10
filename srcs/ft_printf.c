#include "ft_printf.h"

void    ft_init(t_args *args)
{
    args->digit = 0;
    args->base = 0;
    args->minus_flag = 0;
    args->plus_flag = 0;
    args->space_flag = 0;
    args->sharp_flag = 0;
    args->comma_flag = 0;
    args->asterisk_flag = 0;
    args->width_flag = 0;
    args->precision_flag = 0;
    args->hh_flag = 0;
    args->h_flag = 0;
    args->l_flag = 0;
    args->ll_flag = 0;
    args->j_flag = 0;
    args->z_flag = 0;
    args->t_flag = 0;
    args->error_flag = 0;
}

int ft_printf(const char *format, ...)
{
    t_args  *args;
    int     ret;

    if (!format)
        return (-1);
    args = (t_args *)malloc(sizeof(t_args));
    if (!args)
        return (-1);
    ft_init(args);
    args->length = 0;
    args->index = 0;
    args->fmt = format;
    va_start(args->ap, args);
    ft_printf_start(args->ap, format);
    va_end(args->ap);
    ret = args->length;
    free(args);
    return (ret);
}