/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:56:39 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/15 16:06:28 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'\
		|| c == ' ');
}

int	my_atoi(const char *str)
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
	if (*str < '0' || *str > '9')
		ft_exit_argv();
	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		if ((nbr > 2147483647 && minus == 1) || (nbr > 2147483648 && minus == -1))
			ft_exit_argv();
		str++;
	}
	if (*str && ft_isspace(*str) == 0)
		ft_exit_argv();
	return ((int)nbr * minus);
}
