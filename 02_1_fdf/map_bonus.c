/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:44:22 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/17 17:46:53 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

int	ft_check_filename(char *s)
{
	int	i;

	i = ft_strlen((const char*) s);
	if (s[i - 1] != 'f' || s[i - 2] != 'd' || s[i - 3] != 'f' ||
		s[i - 4] != '.')
		return (1);
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
	if (ft_check_filename(filename) != 0)
		return (1);
	return (0);
}