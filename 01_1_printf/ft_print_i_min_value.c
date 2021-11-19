/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i_min_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:33:52 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 15:38:50 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

void	ft_print_d_without_minus(char *str, int *i)
{
	while (*str)
	{
		ft_putchar(*str, i);
		str++;
	}
}

void	ft_check_minus_min_d(t_flags flags, int *i, char *str)
{
	if (flags.minus)
	{
		ft_putchar('-', i);
		ft_print_zero(flags, (int)ft_strlen(str) - 1, i);
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
		ft_print_zero(flags, (int)ft_strlen(str) - 1, i);
		str++;
		ft_print_d_without_minus(str, i);
	}
	return ;
}

void	ft_print_min_value_d(t_flags flags, int *i)
{
	char	*str;

	flags.width--;
	str = malloc(sizeof(int) * 11);
	if (!str)
		return ;
	str = ft_init_str_min_value_d(str);
	if (flags.presicion < (int)ft_strlen(str) - 1)
		flags.presicion = (int)ft_strlen(str) - 1;
	if (flags.presicion < flags.width && flags.zero && flags.point)
		flags.zero = 0;
	ft_check_minus_min_d(flags, i, str);
	free(str);
	return ;
}
