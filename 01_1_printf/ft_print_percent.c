/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:50:57 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 15:05:56 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_percent(char *string, t_flags *flags)
{
	if (ft_strnstr(string, "%", ft_strlen(string)) != NULL)
		flags->percent = 1;
}

void	ft_print_percent(t_flags flags, int *i)
{
	if (!flags.presicion || flags.width <= flags.presicion)
		flags.presicion = 1;
	if (flags.minus)
	{
		if (flags.presicion < flags.width && flags.zero)
			flags.zero = 0;
		ft_putchar('%', i);
		ft_print_space_s(flags, i);
	}
	else
	{
		if (flags.presicion < flags.width && flags.zero)
			flags.presicion = 1;
		ft_print_space_s(flags, i);
		ft_putchar('%', i);
	}
}
