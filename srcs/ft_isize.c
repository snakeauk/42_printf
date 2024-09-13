/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:23:26 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/13 18:16:47 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_isize(int n, char *base)
{
	long long	ln;
	size_t		base_len;
	size_t		size;

	ln = n;
	base_len = ft_strlen(base);
	if (n == 0)
		return (1);
	size = 0;
	if (ln < 0)
	{
		ln = -ln;
		size++;
	}
	while (ln != 0)
	{
		size++;
		ln /= base_len;
	}
	return (size);
}