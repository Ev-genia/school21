/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:04:23 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/18 18:00:22 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->elems);
		free(data);
		exit(0);
	}
	return (0);
}

int	close_win_x(t_data *data)
{
	free(data->elems);
	free(data);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		ft_exit_arg();
	if (ft_check_map(argv[1]) != 0)
		ft_exit_map(argv[1]);
	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		ft_exit_memory();
	ft_alloc_memory(data, argv[1]);
	ft_fill_elems(data, argv[1]);
	ft_init_data(data);
	mlx_loop_hook(data->mlx_ptr, ft_draw, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, close_win, data);
	mlx_hook(data->win_ptr, 17, 0L, close_win_x, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
