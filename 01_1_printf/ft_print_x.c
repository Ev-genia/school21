/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:04:55 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 16:11:49 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_f(char type, t_flags flags, int *i)
{
	if (flags.sharp == 1)
	{
		ft_putchar('0', i);
		ft_putchar(type, i);
		return ;
	}
}

void	ft_print_0_x(unsigned long long int d, t_flags flags, int *i)
{
	if (flags.point && !flags.presicion)
	{
		flags.zero = 0;
		if (flags.width)
			ft_print_space_s(flags, i);
		return ;
	}
	if (flags.presicion < ft_init_count_16(d))
		flags.presicion = ft_init_count_16(d);
	return (ft_check_minus_0(flags, d, i));
}

void	ft_check_minus_x(t_flags flags, int *i, char type, unsigned long long x)
{
	if (flags.minus)
	{
		if (flags.sharp)
		{
			flags.width -= 2;
			ft_check_f(type, flags, i);
		}
		ft_print_zero(flags, ft_init_count_16(x), i);
		ft_nbr_x(x, i, type);
		ft_print_space_s(flags, i);
	}
	else
	{
		if (flags.sharp)
			flags.width -= 2;
		ft_print_space_s(flags, i);
		ft_check_f(type, flags, i);
		ft_print_zero(flags, ft_init_count_16(x), i);
		ft_nbr_x(x, i, type);
	}
	return ;
}

void	ft_print_x(va_list argptr, int *i, t_flags flags)
{
	unsigned int	x;
	char			type;

	type = 'x';
	x = va_arg(argptr, unsigned int);
	if (x == 0)
		return (ft_print_0_x(x, flags, i));
	if (flags.presicion < ft_init_count_16(x))
		flags.presicion = ft_init_count_16(x);
	if (flags.presicion < flags.width && flags.zero && flags.point)
		flags.zero = 0;
	ft_check_minus_x(flags, i, type, x);
}
