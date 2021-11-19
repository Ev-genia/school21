/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_pozitive_negative.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:41:35 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 16:59:27 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

void	ft_check_minus_neg(t_flags flags, int d, int *i, char *str)
{
	if (flags.minus)
	{
		ft_putchar('-', i);
		ft_print_zero(flags, ft_init_count(-d), i);
		str++;
		ft_print_d_without_minus(str, i);
		ft_print_space_s(flags, i);
	}
	else
	{
		if (flags.zero)
		{
			ft_putchar('-', i);
			ft_print_space_s(flags, i);
		}
		else
		{
			ft_print_space_s(flags, i);
			ft_putchar('-', i);
		}
		ft_print_zero(flags, ft_init_count(-d), i);
		str++;
		ft_print_d_without_minus(str, i);
	}
	return ;
}

void	ft_print_negative_d(t_flags flags, int d, int *i, char *str)
{
	flags.width--;
	if (flags.presicion < ft_init_count(-d))
		flags.presicion = ft_init_count(-d);
	if (flags.presicion < flags.width && flags.zero && flags.point)
		flags.zero = 0;
	return (ft_check_minus_neg(flags, d, i, str));
}

void	ft_check_minus_pos(t_flags flags, unsigned int d, int *i, char *str)
{
	if (flags.minus)
	{
		if (flags.plus || flags.space)
		{
			flags.width--;
			ft_check_space_plus(d, flags, i);
		}
		ft_print_zero(flags, ft_init_count(d), i);
		ft_print_d_without_minus(str, i);
		ft_print_space_s(flags, i);
	}
	else
	{
		if (flags.plus || flags.space)
			flags.width--;
		ft_print_space_s(flags, i);
		ft_check_space_plus(d, flags, i);
		ft_print_zero(flags, ft_init_count(d), i);
		ft_print_d_without_minus(str, i);
	}
	return ;
}

void	ft_print_positive_d(t_flags flags, unsigned int d, int *i, char *str)
{
	if (flags.presicion < ft_init_count(d))
		flags.presicion = ft_init_count(d);
	if (flags.presicion < flags.width && flags.zero && flags.point)
		flags.zero = 0;
	return (ft_check_minus_pos(flags, d, i, str));
}
