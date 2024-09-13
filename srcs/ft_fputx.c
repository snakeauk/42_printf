/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:19:21 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/14 00:00:10 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_toupperstr(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		str[index] = ft_toupper(str[index]);
		index++;
	}
	return (str);
}

int ft_fputx(unsigned int unum, int  fd, int c)
{
	char	*str;
	int		ret;

	if ((str = ft_uitoa_base(unum, BASE_LOW_16)) == NULL)
		return (-1);
	if (c == 'X')
		ft_toupperstr(str);
	ret = ft_fputs(str, fd);
	free(str);
	return (ret);
}
