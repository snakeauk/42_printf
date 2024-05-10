/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:41:41 by kinamura          #+#    #+#             */
/*   Updated: 2024/04/28 15:55:33 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*str;

	if (!s || !f)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return ((void *)0);
	index = 0;
	while (str[index])
	{
		str[index] = f(index, str[index]);
		index++;
	}
	return (str);
}
