/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:37:14 by mlarra            #+#    #+#             */
/*   Updated: 2021/10/17 13:07:10 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *d, int c, size_t len)
{
	size_t	i;
	char	*char_d;

	char_d = d;
	i = 0;
	while (i < len)
	{
		char_d[i] = c;
		i++;
	}
	return (char_d);
}
