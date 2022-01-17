/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:11:15 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/17 17:14:11 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(t_elem *elem, t_data *data)
{
	float	prev_x;
	float	prev_y;
	float	angle;

	angle = data->angle;
	prev_x = elem->x;
	prev_y = elem->y;
	elem->x = (prev_x - prev_y) * cos(angle);
	elem->y = -elem->z + (prev_x + prev_y) * sin(angle);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < data->w_width && y > 0 && y < data->w_height)
	{
		dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_draw_line_im(t_elem elem1, t_elem elem2, t_data *data)
{
	float	max_delta;
	float	step_x;
	float	step_y;

	ft_scale_coordinate(&elem1, &elem2, data);
	data->color = ft_choise_color(elem1, elem2);
	ft_isometric(&elem1, data);
	ft_isometric(&elem2, data);
	ft_shift_coordinate(&elem1, &elem2, data);
	step_x = elem2.x - elem1.x;
	step_y = elem2.y - elem1.y;
	max_delta = fmax(fabs(step_x), fabs(step_y));
	step_x /= max_delta;
	step_y /= max_delta;
	while ((int)(elem2.x - elem1.x) || (int)(elem2.y - elem1.y))
	{
		my_mlx_pixel_put(data, elem1.x, elem1.y, data->color);
		elem1.x += step_x;
		elem1.y += step_y;
	}
}

int	ft_draw(t_data *data)
{
	int	i;
	int	j;
	int	ind_i;
	int	ind_j;

	data->img = mlx_new_image(data->mlx_ptr, data->w_width, data->w_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_lenght, &data->endian);
	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			ind_i = j * data->width + i;
			if (i < data->width - 1)
			{
				ft_draw_line_im(data->elems[ind_i], data->elems[ind_i + 1], data);
			}
			ind_j = (j + 1) * data->width + i;
			if (j < data->height - 1)
				ft_draw_line_im(data->elems[ind_j], data->elems[ind_i], data);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img);
	return (0);
}