/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:45:39 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 17:47:35 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_razr_16(unsigned long long int x, int *count)
{
	if (x >= 0 && x < 16)
		(*count)++;
	else
	{
		ft_razr_16(x / 16, count);
		ft_razr_16(x % 16, count);
	}
}

int	ft_init_count_16(unsigned long long int x)
{
	int	count;

	count = 0;
	ft_razr_16(x, &count);
	return (count);
}

void	ft_nbr_x(unsigned long long int x, int *i, char type)
{
	if (x <= 9)
	{
		x = x + '0';
		write(1, &x, 1);
		(*i)++;
	}
	else if (x > 9 && x < 16)
	{
		if (type == 'x' || type == 'p')
			x = x + 'a' - 10;
		else
			x = x + 'A' - 10;
		write(1, &x, 1);
		(*i)++;
	}
	else
	{
		ft_nbr_x(x / 16, i, type);
		ft_nbr_x(x % 16, i, type);
	}
	return ;
}

void	ft_print_X(va_list argptr, int *i, t_flags flags)
{
	unsigned int	X;
	char			type;

	type = 'X';
	X = va_arg(argptr, unsigned int);
	if (X == 0)
		return (ft_print_0_x(X, flags, i));
	if (flags.presicion < ft_init_count_16(X))
		flags.presicion = ft_init_count_16(X);
	if (flags.presicion < flags.width && flags.zero && flags.point)
		flags.zero = 0;
	ft_check_minus_x(flags, i, type, X);
}
