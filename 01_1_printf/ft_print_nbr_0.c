/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:25:44 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 15:31:50 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

void	ft_razr_10(unsigned long long int d, int *count)
{
	if (d >= 0 && d < 10)
		(*count)++;
	else
	{
		ft_razr_10(d / 10, count);
		ft_razr_10(d % 10, count);
	}
}

int	ft_init_count(unsigned long int d)
{
	int	count;

	count = 0;
	ft_razr_10(d, &count);
	return (count);
}

void	ft_print_zero(t_flags flags, int count, int *i)
{
	while (flags.presicion - count > 0)
	{
		ft_putchar('0', i);
		flags.presicion--;
	}
}

void	ft_check_minus_0(t_flags flags, int d, int *i)
{
	if (flags.minus)
	{
		if (flags.plus || flags.space)
		{
			flags.width--;
			ft_check_space_plus(d, flags, i);
		}
		ft_print_zero(flags, ft_init_count(d), i);
		ft_putchar('0', i);
		ft_print_space_s(flags, i);
	}
	else
	{
		if (flags.plus || flags.space)
			flags.width--;
		ft_print_space_s(flags, i);
		ft_check_space_plus(d, flags, i);
		ft_print_zero(flags, ft_init_count(d), i);
		ft_putchar('0', i);
	}
	return ;
}

void	ft_print_0(unsigned int d, t_flags flags, int *i)
{
	if (flags.point && !flags.presicion)
	{
		flags.zero = 0;
		if (flags.width)
			ft_print_space_s(flags, i);
		return ;
	}
	if (flags.presicion < ft_init_count(d))
		flags.presicion = ft_init_count(d);
	return (ft_check_minus_0(flags, d, i));
}
