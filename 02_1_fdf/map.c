/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:07:52 by mlarra            #+#    #+#             */
/*   Updated: 2021/12/15 10:48:02 by mlarra           ###   ########.fr       */
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
		while (words[i] && words[i] != NULL)
			i++;
		if (j > 0)
		{
			if (i != len)
				return (0);
		}
		len = i;
		j++;
		line = get_next_line(fd);
	}

	return (1);
}

int	ft_len_x(int fd)
{
	int		i;
	char	*line;
	char	**words;

	i = 0;
	line = get_next_line(fd);
	words = ft_split((const char *) line, ' ');
	while (words[i] && words[i] != NULL)
			i++;
	return (i);
}

int	ft_len_y(int fd)
{
	int		j;
	char	*line;

	j = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		j++;
		line = get_next_line(fd);
	}
	return (j);
}

void	ft_write_arr(int ****arr_z, int fd)
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
		while (words[i] && words[i] != NULL)
		{
			(***arr_z)[i] = ft_atoi((const char *) words[i]);
			i++;
		}
		len = i;
		j++;
		line = get_next_line(fd);
	}
}

void	ft_close_open(int fd)
{
	close(fd);
	fd = open("42.fdf", O_RDONLY);
}

int	ft_check_map(int ***arr_z)
{
	int		fd;
	int		x;
	int		y;
	// int		len;
	// char	*line;
	// char	**words;

	fd = open("42.fdf", O_RDONLY);
	//check fd!
	if (ft_check_valid_map(fd) != 1)
	{
		close(fd);
		return (0);
	}
	// close(fd);
	// fd = open("42.fdf", O_RDONLY);
	ft_close_open(fd);
	x = ft_len_x(fd);
	// close(fd);
	// fd = open("42.fdf", O_RDONLY);
	ft_close_open(fd);
	y = ft_len_y(fd);
// printf("x: %d, y: %d\n", x, y);
	*arr_z = (int **)malloc(sizeof(int) * x * y);
	if (!(*arr_z))
		return (0);
	// close(fd);
	// fd = open("42.fdf", O_RDONLY);
	ft_close_open(fd);
	ft_write_arr(&arr_z, fd);
	close(fd);
	return (1);
}