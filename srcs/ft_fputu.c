/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 06:50:03 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/13 23:53:17 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputu(unsigned int unum, int fd)
{
	char	*str;
	int		ret;

	if ((str = ft_uitoa_base(unum, BASE_10)) == NULL)
		return (-1);
	ret = ft_fputs(str, fd);
	free(str);
	return (ret);
}
