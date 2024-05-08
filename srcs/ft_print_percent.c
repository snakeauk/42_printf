#include "ft_printf.h"

void ft_print_percent(t_format *f_fmt)
{
    int index;

    index = 0;
    if (f_fmt->flag_index != 2)
    {
        while (index < f_fmt->width -1)
        {
            if  (f_fmt->flag_index != 1)
                write(1, " ", 1);
            else
                write(1, "0", 1);
            f_fmt->length++;
            index++;
        }
        write(1, "%", 1);
        f_fmt->length++;
    }
    else 
    {
        write(1, "%", 1);
        while (index < f_fmt->width - 1)
        {
            write(1, " ", 1);
            f_fmt->length++;
            index++;
        }
    }
}
