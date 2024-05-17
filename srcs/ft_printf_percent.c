#include "ft_printf.h"

int    ft_print_percent(t_args *args)
{
    int ret;

    ret = 0;
    if (!ret)
    {
        args->error_flag++;
        return (ret);
    }
    ret += ft_outchar('%');
    return (ret);
}