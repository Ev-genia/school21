/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:50:21 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 16:51:34 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_p(unsigned long long int n)
{
	int	i;

	i = (n == 0);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*if_null_p(char *dest)
{
	dest[0] = '0';
	dest[1] = '\0';
	return (dest);
}

char	*ft_itoa_p(unsigned long long int n)
{
	char	*dest;
	int		i;

	i = ft_len_p(n);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (dest);
	if (n == 0)
		return (if_null_p(dest));
	dest[i] = '\0';
	while (n != 0)
	{
		i--;
		dest[i] = (char)((n % 10) + '0');
		n = n / 10;
	}
	return (dest);
}
