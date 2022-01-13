#include "fdf.h"

#include <stdio.h>

void	ft_exit_arg()
{
	write(2, "use file of type .fdf in folder ./test_maps\n", 44);
	exit(1);
}

void	ft_exit_fd()
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

	words = ft_split((const char*) line, ' ');
	i = 0;
	while (words[i])
	{
		i++;
		free(words[i]);
	}
	free(words);
	return (i);
}

void	ft_exit_map()
{
	write(2, "map is not valid\n", 17);
	exit(1);
}

int	ft_check_width(char *filename)
{
	int		fd;
	int		i;
	int 	nbrs_first;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
// printf("line1: %s", line);
	nbrs_first = ft_get_width(line);
// printf("nbrs_first: %d\n", nbrs_first);
	free(line);
	line = get_next_line(fd);
// printf("line2: %s", line);
	while (line != NULL)
	{
// printf("line_while: %s", line);
		i = ft_get_width(line);
// printf("i: %d\n", i);
		free(line);
		if (i != nbrs_first)
		{
			close(fd);
			ft_exit_map();
		}
		line = get_next_line(fd);
	}
	close(fd);
	return(0);
}

int	ft_check_map(char *filename)
{
	int	lines;
	int	nbrs_first;
// printf("filename: %s\n", filename);
	lines = ft_get_height(filename);
// printf("lines: %d\n", lines);
	if (lines <= 0)
		return (1);
	nbrs_first = ft_get_width(filename);
	if (ft_check_width(filename) != 0)
		return (1);
	return(0);
}

void	ft_exit_memory()
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
	data->elems = (t_elem *) malloc(sizeof(t_elem) * data->width * data->height + 1);
	if (!data->elems)
		ft_exit_memory();
	data->elems[data->width * data->height + 1].x = 0;
	data->elems[data->width * data->height + 1].y = 0;
	data->elems[data->width * data->height + 1].z = 0;
}

void	ft_fill_dots(char *line, t_data *data, int j)
{
	int	i;
	char	**words;
	i = 0;
		words = ft_split((const char*) line, ' ');
		free(line);
		while (words[i])
		{
			data->elems[j * data->width + i].z = ft_atoi((const char*) words[i]);
			data->elems[j * data->width + i].x = i;
			data->elems[j * data->width + i].y = j;
// printf("(%d, ", (int)data->elems[j * data->width + i].x);
// printf("%d, ", (int)data->elems[j * data->width + i].y);
// printf("%3d", (int)data->elems[j * data->width + i].z);
// printf(") ");
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
// printf("\n");
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
	elem1->x += data->shift;
	elem1->y += data->shift;
	elem2->x += data->shift;
	elem2->y += data->shift;
}

int	ft_choise_color(t_elem elem1, t_elem elem2)
{
	if (elem1.z > 0 || elem2.z > 0)
		return (0xFFFFFF);//0xe80c0c);
	else
		return (0x0000ff);
	// 	return (0x0000ff);//0xe80c0c);
	// else
	// 	return (0xFFFFFF);
}

// void	ft_isometric(t_elem *elem, t_data *data)
// {
// 	float	angle;

// 	angle = data->angle;
// 	elem->x = (elem->x + elem->y) * cos(angle);
// 	elem->y = (elem->x + elem->y) * sin(angle) - elem->z;
// }

void	ft_isometric(t_elem *elem, t_data *data)
{
	float	prev_x;
	float	prev_y;
	float	angle;

	angle = data->angle;
	prev_x = elem->x;
	prev_y = elem->y;
	elem->x = (prev_x - prev_y) * cos(angle);
	elem->y =  -elem->z + (prev_x + prev_y) * sin(angle);

	// elem->x = elem->x * cos(0.7854) - elem->z * sin(0.7854);//0.7854 == 45 grad
	// elem->z = elem->z * cos(0.7854) + elem->x * sin(0.7854);
	// elem->y = elem->y * cos(-0.5236) - elem->z * sin(-0.5236);//-0.5236 == -30 grad
	// elem->z = elem->z * cos(-0.5236) + elem->y * sin(-0.5236);
}

void	ft_draw_line(t_elem elem1, t_elem elem2, t_data *data)
{
	float	max_delta;
	float	step_x;
	float	step_y;

	ft_scale_coordinate(&elem1, &elem2, data);
	data->color = ft_choise_color(elem1, elem2);
	// ft_isometric(&elem1, &elem2);

	ft_isometric(&elem1, data);
	ft_isometric(&elem2, data);

	ft_shift_coordinate(&elem1, &elem2, data);
	// step_x = fmax(fabs(elem1.x), fabs(elem2.x)) - fmin(fabs(elem1.x), fabs(elem2.x));
	// step_y = fmax(fabs(elem1.y), fabs(elem2.y)) - fmin(fabs(elem1.y), fabs(elem2.y));
	step_x = elem2.x - elem1.x;
	step_y = elem2.y - elem1.y;
	// max_delta = fmax(fabs(step_x), fabs(step_y));
	max_delta = fmax(fabs(step_x), fabs(step_y));
	step_x /= max_delta;
	step_y /= max_delta;
	while ((int)(elem2.x - elem1.x) || (int)(elem2.y - elem1.y))
	{

		mlx_pixel_put(data->mlx_ptr, data->win_ptr, elem1.x, elem1.y, data->color);
// printf("test\n");
		elem1.x += step_x;
		elem1.y += step_y;
	}
}

void	ft_draw_map(t_data *data)
{
	int	i;
	int	j;
	int	ind_i;
	int	ind_j;

	j = 0;
printf("data->width: %d\n", data->width);
printf("data->height: %d\n", data->height);
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			ind_i = j * data->width + i;
			if (i < data->width - 1)
			{
// printf("x: %d, y: %d, z: %d\n", (int)data->elems[ind_i].x, (int)data->elems[ind_i].y, (int)data->elems[ind_i].z);
				ft_draw_line(data->elems[ind_i], data->elems[ind_i + 1], data);//right
// printf("x: %d, y: %d, z: %d\n", (int)data->elems[ind_i].x, (int)data->elems[ind_i].y, (int)data->elems[ind_i].z);
// printf("x1: %d, y1: %d, z1: %d\n", (int)data->elems[ind_i + 1].x, (int)data->elems[ind_i + 1].y, (int)data->elems[ind_i + 1].z);
			}
			ind_j = (j + 1) * data->width + i;
			if (j < data->height - 1)
			{
				ft_draw_line(data->elems[ind_j], data->elems[ind_i], data);//down
// printf("x: %d, y: %d, z: %d\n", (int)data->elems[ind_i].x, (int)data->elems[ind_i].y, (int)data->elems[ind_i].z);
// printf("x1: %d, y1: %d, z1: %d\n", (int)data->elems[ind_j].x, (int)data->elems[ind_j].y, (int)data->elems[ind_j].z);
			}
			i++;
		}
		j++;
	}
}

void	ft_init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->scale = 20;
	data->shift = 200;
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_exit_arg();
	if (ft_check_map(argv[1]) != 0)
		ft_exit_map();
	ft_alloc_memory(&data, argv[1]);
	ft_fill_elems(&data, argv[1]);
	ft_init_data(&data);
	ft_draw_map(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, close_win, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}