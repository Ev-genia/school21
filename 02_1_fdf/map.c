/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:07:52 by mlarra            #+#    #+#             */
/*   Updated: 2021/12/17 22:11:29 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	ft_check_valid_map(int fd)
{
	int		i;
	int		j;
	int		len;
	char	*line;
	char	**words;

	j = 0;
	len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		words = ft_split((const char *) line, ' ');
		free(line);
		while (words[i] && words[i] != NULL)
			i++;
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

// void	ft_close_open(int fd, char *file_name)
// {
// 	close(fd);
// 	fd = open(file_name, O_RDONLY);
// }

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
	char	**words;

	fd = open(file_name, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	words = ft_split((const char *) line, ' ');
	free(line);
	while (words[i] && words[i] != NULL)
		i++;
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

// int	ft_malloc_arr(int ***arr_z, t_data *data)
// {
// 	// int	j;

// 	// j = 0;
// 	**arr_z = (int *)malloc(sizeof(int ) * data -> y * data -> y);
// 	if (!(*arr_z))
// 		return (0);
	// while (j < data -> y)
	// {
	// 	(**arr_z)[j] = (int *)malloc(sizeof(int) * (data -> x + 1));
	// 	if (!(**arr_z))
	// 	{
	// 		free_ptr(j, **arr_z);
	// 		return (0);
	// 	}
	// 	j++;
	// }
// 	return (1);
// }

void	ft_fill_arr(int ***arr_z, char *file_name, t_data *data)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**words;

	fd = open(file_name, O_RDONLY);
	j = 0;
	while (j < data -> y)
	{
// printf("\n");
		i = 0;
		line = get_next_line(fd);
// printf("line: %s", line);
		words = ft_split((const char *) line, ' ');
		free(line);
// printf("before i: %d, j: %d\n", i, j);
		while (i < data -> x)
		{
// printf("%s", words[i]);
// printf("words[%d, %d]: %s; ", i, j, words[i]);
// printf("at: %d; ", ft_atoi((const char *) words[i]));
			(**arr_z)[j * data -> x + i] = ft_atoi((const char *) words[i]);
			free(words[i]);
printf("%d ", (**arr_z)[j * data -> x + i]);
// printf("in: i: %d, j: %d", i, j);
			i++;
		}
printf("\n");
		j++;
// printf("end i: %d, j: %d\n", i, j);
	}
	close(fd);
}

// void	ft_fill_arr(int ****arr_z, int fd, char *file_name)
// {
// 	int		i;
// 	char	*line;
// 	char	**words;

// 	ft_close_open(fd, file_name);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// printf("\n");
// 		i = 0;
// 		words = ft_split((const char *) line, ' ');
// 		free(line);
// 		while (words[i] && words[i] != NULL)
// 		{
// 			(***arr_z)[i] = ft_atoi((const char *) words[i]);
// printf("%d ", (***arr_z)[i]);
// 			i++;
// 		}
// 		line = get_next_line(fd);
// 	}
// }

// int	ft_read_error()//int fd)
// {
// 	write(2, "Error reading file", 18);
// 	// close(fd);
// 	return (0);
// }

// int	ft_map_error()//int fd)
// {
// 	write(2, "Map is not valid", 16);
// 	return (0);
// }

int	**ft_check_map(int **arr_z, char *file_name, t_data *data)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
// printf("fd: %d\n", fd);
	if (read(fd, 0, 0) == -1)
	{
		write(2, "Error reading file", 18);
		return (0);
	}
		// return (ft_read_error());//fd));
	if (ft_check_valid_map(fd) != 1)
	{
		write(2, "Map is not valid", 16);
		return (0);
	}
		// return (ft_map_error());//fd));
	data -> y = ft_get_len_y(file_name);
	data -> x = ft_get_len_x(file_name);
	*arr_z = (int *)malloc(sizeof(int ) * data -> y * data -> y);
	if (!(*arr_z))
		return (0);
	// if (ft_malloc_arr(&arr_z, data) != 1)
	// 	return (0);
	ft_fill_arr(&arr_z, file_name, data);
	close(fd);
	return (arr_z);
}