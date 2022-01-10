/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:07:52 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/10 12:26:55 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	ft_word_count(char **line)
{
	int		i;
	char	**words;

	i = 0;
	words = ft_split((const char *) *line, ' ');
	free(*line);
	while (words[i] && words[i] != NULL)
	{
		i++;
		free(words[i]);
	}
	free(words);
	return (i);
}

int	ft_close(int fd)
{
	close(fd);
	return (0);
}

int	ft_check_valid_map(int fd)
{
	int		i;
	int		j;
	int		len;
	char	*line;

	j = 0;
	len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = ft_word_count(&line);
		if (j > 0)
		{
			if (i != len)
			{
				close(fd);
				return (0);
			}
		}
		len = i;
		j++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	ft_get_len_y(char *file_name)
{
	int		j;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	j = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		j++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (j);
}

int	ft_get_len_x(char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	i = ft_word_count(&line);
	close(fd);
	return (i);
}

void	free_ptr(int j, int **ptr)
{
	while (j > 0)
	{
		free(ptr[j - 1]);
		j--;
	}
	free(ptr);
}

// void	ft_fill_arr(int ***arr_z, char *file_name, t_data *data)
void	ft_fill_arr(char *file_name, t_data **data)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**words;

	fd = open(file_name, O_RDONLY);
	j = 0;
	while (j < (*data)->height)//y)
	{
		i = 0;
		line = get_next_line(fd);
		words = ft_split((const char *) line, ' ');
		free(line);
		while (i < (*data)->width)//x)
		{
			((*data)->arr_z)[j * (*data)->width + i].z = ft_atoi((const char *) words[i]);//x + i] = ft_atoi((const char *) words[i]);
printf("%3d", ((*data)->arr_z)[j * (*data)->width + i].z);//x + i]);
			((*data)->arr_z)[j * (*data)->width + i].x = i;
			((*data)->arr_z)[j * (*data)->width + i].y = j;
			free(words[i]);
			i++;
		}
		free(words);
		j++;
printf("\n");
	}
	close(fd);
}

// int	**ft_check_map(int **arr_z, char *file_name, t_data *data)
t_coordinate	**ft_check_map(char *file_name, t_data *data)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error reading file", 18);
		return (0);
	}
	if (ft_check_valid_map(fd) != 1)
	{
		write(2, "Map is not valid", 16);
		return (0);
	}
	data->height = ft_get_len_y(file_name);//y = ft_get_len_y(file_name);
	data->width = ft_get_len_x(file_name);//x = ft_get_len_x(file_name);
	data->arr_z = (t_coordinate *)malloc(sizeof(t_coordinate) * (data->width + 1) * (data->height + 1));//x + 1) * (data->y + 1));
	if (!(data->arr_z))
		return (0);
	// ft_fill_arr(&arr_z, file_name, data);
	ft_fill_arr(file_name, &data);
	close(fd);
	// return (arr_z);
	return (&data->arr_z);
}