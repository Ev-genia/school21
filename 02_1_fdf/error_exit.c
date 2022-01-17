/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:56:36 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/17 16:58:27 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit_arg(void)
{
	write(2, "use one file of type .fdf in folder ./test_maps\n", 48);
	exit(1);
}

void	ft_exit_fd(void)
{
	write(2, "file is not readble\n", 20);
	exit(1);
}

void	ft_exit_map(void)
{
	write(2, "map is not valid\n", 17);
	exit(1);
}

void	ft_exit_memory(void)
{
	write(2, "memory not allocated\n", 21);
	exit(1);
}