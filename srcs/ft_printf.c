#include "ft_printf.h"

void    ft_init(t_args *args)
{
    args->digit = 0;
    args->base = 0;
    args->minus_flag = 0;
    args->plus_flag = 0;
    args->space_flag = 0;
    args->sharp_flag = 0;
    args->zero_flag = 0;
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

// void    ft_printf_flags(t_args *args)
// {
//     if (args->fmt[args->index] == '-')
//         args->minus_flag++;
//     else if (args->fmt[args->index] == '+')
//         args->plus_flag++;
//     else if (args->fmt[args->index] == ' ')
//         args->space_flag++;
//     else if (args->fmt[args->index] == '#')
//         args->sharp_flag++;
//     else if (args->fmt[args->index] == ',')
//         args->comma_flag++;
//     return ;
// }
// void    ft_printf_width(t_args *args)
// {
//     while (ft_isdigit(args->fmt[args->index]))
//         args->width_flag += args->width_flag * 10 + (args->fmt[args->index] - '0');
//     if (args->fmt[args->index] == '*')
//         args->asterisk_flag++;
// }

// void    ft_printf_precision(t_args *args)
// {
// }

void    ft_printf_type(t_args *args)
{
    if (args->fmt[args->index] == 'c')
        args->length += ft_printf_c(args);
    else if (args->fmt[args->index] == 's')
        args->length += ft_printf_s(args);
    else if (args->fmt[args->index] == 'p')
        args->length += ft_printf_p(args);
    else if (args->fmt[args->index] == 'd')
        args->length += ft_printf_d(args);
    else if (args->fmt[args->index] == 'i')
        args->length += ft_printf_i(args);
    else if (args->fmt[args->index] == 'u')
        args->length += ft_printf_u(args);
    else if (args->fmt[args->index] == 'x')
        args->length += ft_printf_x(args);
    else if (args->fmt[args->index] == 'X')
        args->length += ft_printf_large_x(args);
    else if (args->fmt[args->index] == '%')
        args->length += ft_print_percent(args);
    else if (args->width_flag > 0)
        args->error_flag++;
}

void    ft_printf_format(t_args *args)
{
    while (args->fmt[args->index])
    {
        if (args->fmt[args->index] == '%')
        {
            args->index++;
            // ft_printf_flags(args);
            // ft_printf_width(args);
            // ft_printf_precision(args);
            ft_printf_type(args);
            if (args->error_flag)
                args->length++;
        }
        else
            args->length += ft_outchar(args->fmt[args->index]);
        ft_init(args);
        args->index++;
    }
}

void    ft_printf_start(t_args *args)
{
    if (!ft_strchr(args->fmt, '%'))
    {
        ft_outstr(args->fmt);
        args->length = ft_strlen(args->fmt);
        return ;
    }
    ft_printf_format(args);
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
    ret = 0;
    args->length = 0;
    args->index = 0;
    args->fmt = (char *)format;
    va_start(args->ap, format);
    ft_printf_start(args);
    va_end(args->ap);
    ret = args->length;
    // if (args->error_flag)
    // {
    //     free(args);
    //     return (-1);
    // }
    free(args);
    return (ret);
}

// #include <stdio.h>
// int main (void)
// {
//     int ft_ret;
//     int ret;
//     char *s = "ft_printf:";
//     char *line = "=======================================\n=======================================\n";
//     while (*line)
//     {
//         write(1, line, 1);
//         line++;
//     }
//     while (*s)
//     {
//         write(1, s, 1);
//         s++;
//     }
//     ft_ret = ft_printf(" %c %c %c ", '2', '1', 0);
//     printf("\n");
//     printf("   printf:");
// /*-------------------------------------------*/
//     ret = printf(" %c %c %c ", '2', '1', 0);
// /*-------------------------------------------*/
//     printf("\n");
//     printf("ft_printf:%d\n   printf:%d\n", ft_ret, ret);
//     return (0);
// }