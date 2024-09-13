/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:56:43 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/14 00:07:40 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_fputp(unsigned long long unum, int fd)
{
	size_t	ret;
	size_t	w_ret;
	char	*str;

	ret = 0;
	if ((w_ret = ft_fputs("0x", fd)) < 0)
		return (-1);
	ret += w_ret;
	if ((str = ft_ulltoa_base(unum, BASE_LOW_16)) == NULL)
		return (-1);
	if ((w_ret = ft_fputs(str, fd)) < 0)
		return (-1);
	ret += w_ret;
	free(str);
	return (ret);
}
