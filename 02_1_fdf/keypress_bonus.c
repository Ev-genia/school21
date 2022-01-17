/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:56:32 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/17 19:09:11 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

// void	ft_plate_projection(t_data *data)
// {
// 	mlx_loop_hook(data->mlx_ptr, ft_draw_XoY, data);
// 	mlx_clear_window(data->mlx_ptr, data->win_ptr);
// 	ft_draw_XoY(data);
// }

// void	ft_iso_projection(t_data *data)
// {
// 	mlx_loop_hook(data->mlx_ptr, ft_draw, data);
// 	mlx_clear_window(data->mlx_ptr, data->win_ptr);
// 	ft_draw(data);
// }

void	ft_change_projection(int key, t_data *data)
{
	if ((key == 15) && (data->elems[data->width * data->height].y < data->w_height))//r
	{
		mlx_loop_hook(data->mlx_ptr, ft_draw_XoY, data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_draw_XoY(data);
	}
		// ft_plate_projection(data);
	else if (key == 17)//t
	{
		mlx_loop_hook(data->mlx_ptr, ft_draw, data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_draw(data);
	}
		// ft_iso_projection(data);
}

int	deal_key(int key, t_data *data)
{
	if (key == 126)
		data->shift_y -= 10;
	else if (key == 125)
		data->shift_y += 10;
	else if (key == 124)
		data->shift_x += 10;
	else if (key == 123)
		data->shift_x -= 10;
	else if (key == 32)
		data->shift_z += 2;
	else if (key == 2)
		data->shift_z -= 2;
	else if (key == 34)
		data->scale++;
	else if (key == 37)
		data->scale--;
	else if (key == 0)
		data->angle -= 0.1;
	else if (key == 1)
		data->angle += 0.1;
	ft_change_projection(key, data);
	// else if ((key == 15) && (data->elems[data->width * data->height].y < data->w_height))//r
	// 	ft_plate_projection(data);
	// else if (key == 17)//t
	// 	ft_iso_projection(data);
	return (0);
}