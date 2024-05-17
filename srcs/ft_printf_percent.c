#include "ft_printf.h"

int    ft_print_percent(t_args *args)
{
    int ret;

    ret = 0;
    if (ret != 0)
    {
        args->error_flag++;
        return (ret);
    }
    ret += ft_outchar('%');
    return (ret);
}