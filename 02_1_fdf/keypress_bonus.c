/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:56:32 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/18 13:46:18 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_change_projection(int key, t_data *data)
{
	if (key == 15)
	{
		mlx_loop_hook(data->mlx_ptr, ft_draw_XoY, data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_draw_XoY(data);
	}
	else if (key == 17)
	{
		mlx_loop_hook(data->mlx_ptr, ft_draw, data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_draw(data);
	}
}

int	ft_close_win(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->elems);
	exit(0);
	return (0);
}

int	deal_key(int key, t_data *data)
{
	if (key == 53)
		ft_close_win(data);
	if (key == 126)
		data->shift_y--;
	else if (key == 125)
		data->shift_y++;
	else if (key == 124)
		data->shift_x++;
	else if (key == 123)
		data->shift_x--;
	else if (key == 32)
		data->shift_z++;
	else if (key == 2)
		data->shift_z--;
	else if (key == 34)
		data->scale++;
	else if (key == 37)
		data->scale--;
	else if (key == 0)
		data->angle -= 0.1;
	else if (key == 1)
		data->angle += 0.1;
	ft_change_projection(key, data);
	return (0);
}
