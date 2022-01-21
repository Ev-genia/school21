/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:56:39 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/21 16:36:11 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'\
		|| c == ' ');
}

int	ft_atoi(const char *str)
{
	int					minus;
	unsigned long int	nbr;

	while (*str && ft_isspace(*str))
		str++;
	minus = 1;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		if (nbr > 9223372036854775807 && minus == 1)
			return (-1);
		if (nbr > 9223372036854775807 && minus == -1)
			return (0);
		str++;
	}
	return ((int)nbr * minus);
}
