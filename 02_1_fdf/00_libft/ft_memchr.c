/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:12:22 by mlarra            #+#    #+#             */
/*   Updated: 2021/10/18 16:47:55 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*us;

	us = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*us == (unsigned char)c)
			return (us);
		i++;
		us++;
	}
	return (NULL);
}
