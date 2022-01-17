/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:15:02 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/17 17:15:44 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_scale(t_data *data)
{

	if (data->width > data->height)
		data->scale = (int)(data->w_height / data->height / 2);
	else
		data->scale = (int)(data->w_width / data->width / 2);
}

void	ft_get_shift(t_data *data)
{
	data->shift_x = (int)((data->w_width - data->width) / 2);
	data->shift_y = (int)((data->w_height - data->height) / 4);
}

void	ft_init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->w_width = 1000;
	data->w_height = 700;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w_width, data->w_height, "FDF");
	ft_get_scale(data);
	ft_get_shift(data);
	data->angle = 0.523599;
}