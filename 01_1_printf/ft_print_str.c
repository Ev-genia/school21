/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:09:58 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 17:48:45 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_str(char *str, int *i, t_flags flags)
{
	while (*str && flags.presicion > 0)
	{
		ft_putchar(*str, i);
		str++;
		flags.presicion--;
	}
}

void	ft_presicion_less_width_s(char *str, int*i, t_flags flags)
{
	if (flags.width > flags.presicion)
	{
		if (flags.minus)
		{
			ft_write_str(str, i, flags);
			ft_print_space_s(flags, i);
			return ;
		}
		else
		{
			ft_print_space_s(flags, i);
			ft_write_str(str, i, flags);
			return ;
		}
	}
	ft_write_str(str, i, flags);
	return ;
}

void	ft_check_presicion_s(char *str, int*i, t_flags flags)
{
	if (flags.presicion > (int)ft_strlen(str))
		flags.presicion = (int)ft_strlen(str);
	return (ft_presicion_less_width_s(str, i, flags));
}

void	ft_check_s_null(char *str, t_flags flags, int *i)
{
	str = (char *)malloc(sizeof(char) * (6 + 1));
	str = ft_inti_null_str(str);
	if (flags.presicion)
	{
		ft_check_presicion_s(str, i, flags);
		free(str);
		return ;
	}
	flags.presicion = (int)ft_strlen(str);
	if (flags.minus || flags.width)
	{
		ft_presicion_less_width_s(str, i, flags);
		free(str);
		return ;
	}
	ft_write_str(str, i, flags);
	free(str);
}

void	ft_print_s(va_list argptr, int *i, t_flags flags)
{
	char	*str;

	str = va_arg(argptr, char *);
	if (!str)
	{
		ft_check_s_null(str, flags, i);
		return ;
	}
	if (flags.presicion || flags.point)
	{
		ft_check_presicion_s(str, i, flags);
		return ;
	}
	flags.presicion = (int)ft_strlen(str);
	if (flags.minus || flags.width)
	{
		ft_presicion_less_width_s(str, i, flags);
		return ;
	}
	ft_write_str(str, i, flags);
}
