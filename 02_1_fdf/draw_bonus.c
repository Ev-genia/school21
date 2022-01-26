/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:43:09 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/19 15:34:46 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < data->w_width && y > 0 && y < data->w_height)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_draw_line(t_elem elem1, t_elem elem2, t_data *data)
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
	ft_get_addr(data);
	mlx_hook(data->win_ptr, 2, 0, deal_key, data);
	j = -1;
	while (++j < data->height)
	{
		i = -1;
		while (++i < data->width)
		{
			ind_i = j * data->width + i;
			if (i < data->width - 1)
				ft_draw_line(data->elems[ind_i], data->elems[ind_i + 1], data);
			ind_j = (j + 1) * data->width + i;
			if (j < data->height - 1)
				ft_draw_line(data->elems[ind_j], data->elems[ind_i], data);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img);
	return (0);
}

void	ft_line_XoY(t_elem elem1, t_elem elem2, t_data *data)
{
	float	max_delta;
	float	step_x;
	float	step_y;

	ft_scale_coordinate(&elem1, &elem2, data);
	data->color = ft_choise_color(elem1, elem2);
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

int	ft_draw_XoY(t_data *data)
{
	int	i;
	int	j;
	int	ind_i;
	int	ind_j;

	data->img = mlx_new_image(data->mlx_ptr, data->w_width, data->w_height);
	ft_get_addr(data);
	j = -1;
	while (++j < data->height)
	{
		i = -1;
		while (++i < data->width)
		{
			ind_i = j * data->width + i;
			if (i < data->width - 1)
				ft_line_XoY(data->elems[ind_i], data->elems[ind_i + 1], data);
			ind_j = (j + 1) * data->width + i;
			if (j < data->height - 1)
				ft_line_XoY(data->elems[ind_j], data->elems[ind_i], data);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img);
	return (0);
}
