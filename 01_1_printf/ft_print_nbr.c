/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:42:37 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 17:48:29 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

void	ft_putnbr(unsigned int n, int *i)
{
	if (n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
		(*i)++;
	}
	else
	{
		ft_putnbr(n / 10, i);
		ft_putnbr(n % 10, i);
	}
	return ;
}

void	ft_check_space_plus(unsigned int d, t_flags flags, int *i)
{
	if (flags.plus && d >= 0)
	{
		ft_putchar('+', i);
		return ;
	}
	else if (flags.space && d >= 0)
	{
		ft_putchar(' ', i);
		return ;
	}
}

void	ft_check_width_d(t_flags flags, char *str, int *i)
{
	if (flags.width > (int)ft_strlen(str))
	{
		while (flags.width > (int)ft_strlen(str))
		{
			ft_putchar(' ', i);
			flags.width--;
		}
	}
}

void	ft_print_i(va_list argptr, int *i, t_flags flags)
{
	int		d;
	char	*str;

	d = va_arg(argptr, int);
	if (d == 0)
		return (ft_print_0(d, flags, i));
	if (d == -2147483648)
	{
		ft_print_min_value_d(flags, i);
		return ;
	}
	str = ft_itoa(d);
	if (d < 0)
	{
		ft_print_negative_d(flags, d, i, str);
		free(str);
		return ;
	}
	else
	{
		ft_print_positive_d(flags, d, i, str);
		free(str);
	}
}

void	ft_print_u(va_list argptr, int *i, t_flags flags)
{
	unsigned int	u;
	char			*str;

	u = va_arg(argptr, unsigned int);
	if (u == 0)
		return (ft_print_0(u, flags, i));
	str = ft_itoa_p(u);
	ft_print_positive_d(flags, u, i, str);
	free(str);
}
