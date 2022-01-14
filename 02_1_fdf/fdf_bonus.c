/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:04:23 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/14 19:04:58 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

#include <stdio.h>

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

int	ft_get_height(char *filename)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit_fd();
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	ft_get_width(char *line)
{
	int		i;
	char	**words;

	words = ft_split((const char *) line, ' ');
	i = 0;
	while (words[i])
	{
		i++;
		free(words[i]);
	}
	free(words);
	return (i);
}

void	ft_exit_map(void)
{
	write(2, "map is not valid\n", 17);
	exit(1);
}

int	ft_check_width(char *filename)
{
	int		fd;
	int		i;
	int		nbrs_first;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	nbrs_first = ft_get_width(line);
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = ft_get_width(line);
		free(line);
		if (i != nbrs_first)
		{
			close(fd);
			ft_exit_map();
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	ft_check_map(char *filename)
{
	int	lines;
	int	nbrs_first;

	lines = ft_get_height(filename);
	if (lines <= 0)
		return (1);
	nbrs_first = ft_get_width(filename);
	if (ft_check_width(filename) != 0)
		return (1);
	return (0);
}

void	ft_exit_memory(void)
{
	write(2, "memory not allocated\n", 21);
	exit(1);
}

void	ft_alloc_memory(t_data *data, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	data->width = ft_get_width(line);
	free(line);
	close(fd);
	data->height = ft_get_height(filename);
	data->elems = \
		(t_elem *) malloc(sizeof(t_elem) * data->width * data->height);
	if (!data->elems)
		ft_exit_memory();
}

void	ft_fill_dots(char *line, t_data *data, int j)
{
	int		i;
	char	**words;

	i = 0;
	words = ft_split((const char *) line, ' ');
	free(line);
	while (words[i])
	{
		data->elems[j * data->width + i].z = ft_atoi((const char *) words[i]);
		data->elems[j * data->width + i].x = i;
		data->elems[j * data->width + i].y = j;
		free(words[i]);
		i++;
	}
	free(words);
}

void	ft_fill_elems(t_data *data, char *filename)
{
	int		fd;
	int		j;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	j = 0;
	while (line)
	{
		ft_fill_dots(line, data, j);
		line = get_next_line(fd);
		j++;
	}
}

void	ft_scale_coordinate(t_elem *elem1, t_elem *elem2, t_data *data)
{
	elem1->x *= data->scale;
	elem1->y *= data->scale;
	elem2->x *= data->scale;
	elem2->y *= data->scale;
}

void	ft_shift_coordinate(t_elem *elem1, t_elem *elem2, t_data *data)
{
	elem1->x += data->shift_x;
	elem1->y += data->shift_y;
	elem2->x += data->shift_x;
	elem2->y += data->shift_y;
}

int	ft_choise_color(t_elem elem1, t_elem elem2)
{
	if (elem1.z > 0 || elem2.z > 0)
		return (0xFFFFFF);
	else
		return (0x0000ff);
}

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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
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
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, \
		&data->endian);
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
	data->shift_z = 2;
}

void	ft_init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->w_width = 1000;
	data->w_height = 700;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w_width, \
		data->w_height, "FDF");
	ft_get_scale(data);
	ft_get_shift(data);

	data->angle = 0.523599;
}

int	close_win(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->elems);
		exit(0);
	}
	return (0);
}

int	deal_key(int key, t_data *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 32)
		data->shift_z += 2;
	if (key == 2)
		data->shift_z -= 2;
	if (key == 34)
		data->scale++;
	if (key == 37)
		data->scale--;
	if (key == 0)
		data->angle -= 0.1;
	if (key == 1)
		data->angle += 0.1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_draw(data);
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
		ft_exit_map();

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		ft_exit_memory();
	ft_alloc_memory(data, argv[1]);
	ft_fill_elems(data, argv[1]);
	ft_init_data(data);
	mlx_loop_hook(data->mlx_ptr, ft_draw, data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, close_win, data);
	mlx_hook(data->win_ptr, 17, 0L, close_win_x, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
