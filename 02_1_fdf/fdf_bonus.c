/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:04:23 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/18 13:43:35 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_isometric(t_elem *elem, t_data *data)
{
	float	prev_x;
	float	prev_y;
	float	angle;

	angle = data->angle;
	prev_x = elem->x;
	prev_y = elem->y;
	elem->x = (prev_x - prev_y) * cos(angle);
	elem->y = -elem->z * data->shift_z + (prev_x + prev_y) * sin(angle);
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
		ft_exit_map();
	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		ft_exit_memory();
	ft_alloc_memory(data, argv[1]);
	ft_fill_elems(data, argv[1]);
	ft_init_data(data);
	mlx_loop_hook(data->mlx_ptr, ft_draw, data);
	mlx_hook(data->win_ptr, 17, 0L, close_win_x, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
