#include "fdf.h"

#include <stdio.h>

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	ft_mod(float a)
{
	if (a < 0)
		a = a * (-1);
	return (a);
}

int	ft_choice_color(int z1, int z2)
{
	if (z1 > 0 || z2 > 0)
		return (0x0000ff);//0xe80c0c);
	else
		return (0xFFFFFF);
}

void	ft_isometric(float *x, float *y, int z)
{
	// float	prev_x;
	// float	prev_y;

	// prev_x = *x;
	// prev_y = *y;
	*x = (*x - *y) * cos(0.7);
	*y = (*x + *y) * sin(0.7) - z;
	// *x = (prev_x - prev_y) * cos(0.7);
	// *y = (prev_x + prev_y) * sin(0.7) - z;
}

void	ft_koodrinate_shift(float *x1, float *y1, float *x2, float *y2)
{
	float	shift;

	shift = 200;
	*x1 += shift;
	*y1 += shift;
	*x2 += shift;
	*y2 += shift;
}

// void	draw_line(float x1, float y1, float x2, float y2, t_data *data)
void	draw_line(t_coordinate elem1, t_coordinate elem2, t_data *data)
{
	float	delta_x;
	float	delta_y;
	float	max_delta;
	float	step_x;
	float	step_y;
	int		z1;
	int		z2;

	// z1 = data->arr_z[(int)(y1 * data->width + x1)].z;//x + x1)];
	z1 = elem1.z;
	// z2 = data->arr_z[(int)(y2 * data->width + x2)].z;//x + x2)];
	z2 = elem2.z;
printf(" %d, %d; ", z1, z2);
	elem1.x = elem1.x * data->scale;
	elem1.y = elem1.y * data->scale;
	elem2.x = elem2.x * data->scale;
	elem2.y = elem2.y * data->scale;
	// x2 = x2 * data->scale;
	// y2 = y2 * data->scale;
	// data->color = ft_choice_color(z1, z2);
	data->color = ft_choice_color(elem1.z, elem2.z);
	// ft_isometric(&x1, &y1, z1);
	// ft_isometric(&x2, &y2, z2);
	// ft_koodrinate_shift(&x1, &y1, &x2, &y2);
	delta_x = ft_max(ft_mod(elem1.x), ft_mod(elem2.x)) - ft_min(ft_mod(elem1.x), ft_mod(elem2.x));
	delta_y = ft_max(ft_mod(elem1.y), ft_mod(elem2.y)) - ft_min(ft_mod(elem1.y), ft_mod(elem2.y));
	max_delta = ft_max(delta_x, delta_y);
	step_x = delta_x / max_delta;
	step_y = delta_y / max_delta;
	while ((elem1.x < elem2.x) || (elem1.y < elem2.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, elem1.x, elem1.y, data->color);
		elem1.x = elem1.x + step_x;
		elem1.y = elem1.y + step_y;
	}
}

// void	draw_map(t_data *data, int *arr_z)
void	draw_map(t_data *data)
{
	int	i;
	// int	delta_i;
	int	j;
	// int	delta_j;
	// int	z;
	// int	z1;

	j = 0;
	// i = 0;
	// z = arr_z[j * data->x + i];
	// z1 = 
	// delta_j = 0;
	// delta_i = 100;
	
	// while ((j + delta_j) <= (data->y - 1 + delta_j))
	while (j < data->height)//y)
	{
		i = 0;
		while (i < data->width)//x)
		{
// printf("x: %d, y: %d\n", i, j);
			if (i < (data->width - 1))//x - 1))
				draw_line(data->arr_z[j * (data->width + i)], data->arr_z[j * (data->width + i + 1)], data);//i, j, (i + 1), j, data);
			draw_line(data->arr_z[j * (data->width + i)], data->arr_z[(j + 1) * (data->width + i)], data);
			i++;
		}
		j++;
	}
	i = 0;
	while (i < (data->width - 1))//x - 1))
	{
		draw_line(data->arr_z[j * (data->width + i)], data->arr_z[j * (data->width + i + 1)], data);
		i++;
	}
}