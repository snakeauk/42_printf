/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 06:15:30 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/14 01:22:54 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputs(const char *s, int fd)
{
	char	*str;
	int		ret;

	if (s == NULL)
		return (ft_fputs("(null)", fd));
	else
		str = ft_strdup(s);
	if (!str)
		return (-1);
	ret = write(fd, str, ft_strlen(str));
	free(str);
	return (ret);
}
