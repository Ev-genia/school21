/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:03:38 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/18 17:20:10 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	data->elems = (t_elem *) \
		malloc(sizeof(t_elem) * data->width * data->height);
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
