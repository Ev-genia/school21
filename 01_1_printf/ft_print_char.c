/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:33:27 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 17:47:07 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

void	ft_print_space_s(t_flags flags, int *i)
{
	while (flags.width - flags.presicion > 0)
	{
		if (flags.zero)
			ft_putchar('0', i);
		else
			ft_putchar(' ', i);
		flags.width--;
	}
}

void	ft_print_c(va_list argptr, int *i, t_flags flags)
{
	char	c;

	c = va_arg(argptr, int);
	if (!flags.presicion)
		flags.presicion = 1;
	if (flags.width)
	{
		if (flags.minus)
		{
			ft_putchar(c, i);
			ft_print_space_s(flags, i);
		}
		else
		{
			ft_print_space_s(flags, i);
			ft_putchar(c, i);
		}
	}
	else
		ft_putchar(c, i);
}
