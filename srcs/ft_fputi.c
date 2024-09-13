/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:14:03 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/13 15:47:26 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputi(int num, int fd)
{
	char	*str;
	int		ret;

	if ((str = ft_itoa_base(num, BASE_10)) == NULL)
		return (-1);
	ret = ft_fputs(str, fd);
	free(str);
	return (ret);
}
