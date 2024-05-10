#include "ft_printf.h"

void    ft_print_precision(t_format *f_fmt)
{
    size_t  count;

    count = 0;
    write(1, "%", 1);
    while (count < (f_fmt->width - 1))
    {
        write(1, " ", 1);
        f_fmt->length++;
        count++;
    }
}

void    ft_print_add_config(t_format *f_fmt)
{
    size_t count;

    count = 0;
    while (count < f_fmt->width -1)
    {
        if  (f_fmt->index_flag != 1)
            write(1, " ", 1);
        else
            write(1, "0", 1);
        f_fmt->length++;
        count++;
    }
    write(1, "%", 1);
    f_fmt->length++;
}

void    ft_print_percent(t_format *f_fmt)
{
    if (f_fmt->index_flag != 2)
        ft_print_add_config(f_fmt);
    else
        ft_print_precision(f_fmt);
}
