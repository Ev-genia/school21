/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:19:22 by mlarra            #+#    #+#             */
/*   Updated: 2021/10/22 14:53:54 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	len_s;

	if (!s)
		return ;
	len_s = ft_strlen(s);
	while (len_s > 0)
	{
		len_s--;
		f((unsigned int)len_s, &s[len_s]);
	}
}
