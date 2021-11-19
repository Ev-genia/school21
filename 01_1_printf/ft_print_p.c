/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:12:30 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 16:22:17 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_minus_0_p(t_flags flags, unsigned long long int p, int *i)
{
	flags.width -= 2;
	if (flags.minus)
	{
		ft_putchar('0', i);
		ft_putchar('x', i);
		ft_print_zero(flags, ft_init_count_16(p), i);
		ft_putchar('0', i);
		ft_print_space_s(flags, i);
	}
	else
	{
		ft_print_space_s(flags, i);
		ft_putchar('0', i);
		ft_putchar('x', i);
		ft_print_zero(flags, ft_init_count_16(p), i);
		ft_putchar('0', i);
	}
	return ;
}

void	ft_print_0_p(unsigned long long int p, t_flags flags, int *i)
{
	if (flags.presicion < ft_init_count_16(p))
		flags.presicion = ft_init_count_16(p);
	return (ft_check_minus_0_p(flags, p, i));
}

void	ft_check_minus_p(t_flags flags, int *i, char type, \
		unsigned long long int p)
{
	flags.width -= 2;
	if (flags.minus)
	{
		ft_putchar('0', i);
		ft_putchar('x', i);
		ft_print_zero(flags, ft_init_count_16(p), i);
		ft_nbr_x(p, i, type);
		ft_print_space_s(flags, i);
	}
	else
	{
		ft_print_space_s(flags, i);
		ft_putchar('0', i);
		ft_putchar('x', i);
		ft_print_zero(flags, ft_init_count_16(p), i);
		ft_nbr_x(p, i, type);
	}
	return ;
}

void	ft_print_p(va_list argptr, int *i, t_flags flags)
{
	unsigned long long int	p;
	char					type;

	type = 'p';
	p = va_arg(argptr, unsigned long long int);
	if (p == 0)
		return (ft_print_0_p(p, flags, i));
	if (flags.presicion < ft_init_count_16(p))
		flags.presicion = ft_init_count_16(p);
	ft_check_minus_p(flags, i, type, p);
}
