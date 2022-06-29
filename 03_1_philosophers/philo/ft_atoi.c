/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:56:39 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/28 21:55:09 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'\
		|| c == ' ');
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	number;
	unsigned int	last_num;

	sign = 1;
	number = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		last_num = number;
		number = number * 10 + (*str - '0');
		if (number < last_num)
			return (0);
		str++;
	}
	return (number * sign);
}
