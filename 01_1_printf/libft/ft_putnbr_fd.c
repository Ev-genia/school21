/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:15:43 by mlarra            #+#    #+#             */
/*   Updated: 2021/10/22 17:32:35 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nbr(int n, int fd)
{
	if (n <= 9)
	{
		n = n + '0';
		write(fd, &n, 1);
	}
	else
	{
		ft_nbr(n / 10, fd);
		ft_nbr(n % 10, fd);
	}
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 2147483647)
	{
		write(fd, "2147483647", 10);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0 && n <= 2147483647)
	{
		n = n * (-1);
		write(fd, "-", 1);
	}
	ft_nbr(n, fd);
}
