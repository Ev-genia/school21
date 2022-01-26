/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:54 by mlarra            #+#    #+#             */
/*   Updated: 2021/10/22 14:11:58 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!dest)
		return (dest);
	dest[len_s] = '\0';
	while (len_s > 0)
	{
		len_s--;
		dest[len_s] = (f)((unsigned char)len_s, s[len_s]);
	}
	return (dest);
}
