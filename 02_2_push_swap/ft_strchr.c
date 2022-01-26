/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:15:13 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/25 11:21:06 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return ((void *)0);
	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return ((void *)0);
		i++;
	}
	return ((char *)&s[i]);
}
