/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:41:29 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/17 16:43:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

char	*ft_reading_buf(int fd, char *buf, char *tail)
{
	int		nbytes;

	nbytes = 1;
	while (nbytes != 0 && ft_strchr(tail, '\n') == NULL)
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes < 0)
		{
			free ((void *)buf);
			return ((void *)0);
		}
		buf[nbytes] = '\0';
		if (tail)
			tail = ft_strjoin(tail, buf);
		else
			tail = ft_substr(buf, 0, nbytes);
	}
	free((void *)buf);
	return (tail);
}

char	*ft_get_line(char *tail)
{
	int		i;
	char	*dest;

	i = 0;
	while (tail[i] && tail[i] != '\n')
		i++;
	if (tail[i] == '\n')
		i++;
	dest = ft_substr(tail, 0, i);
	return (dest);
}

char	*ft_get_tail(char *tail)
{
	int		i;
	char	*ret_tail;

	i = 0;
	while (tail[i] && tail[i] != '\n')
		i++;
	i++;
	ret_tail = ft_substr(tail, i, ft_strlen(tail));
	free ((void *)tail);
	return (ret_tail);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*dest;
	static char	*tail[1025];

	if (fd < 0 || BUFFER_SIZE < 1)
		return ((void *)0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ((void *)0);
	tail[fd] = ft_reading_buf(fd, buf, tail[fd]);
	if (!tail[fd] || tail[fd][0] == '\0')
	{
		free((void *)tail[fd]);
		tail[fd] = 0;
		return ((void *)0);
	}
	dest = ft_get_line(tail[fd]);
	if (!dest || dest[0] == '\0')
	{
		free ((void *)dest);
		return ((void *)0);
	}
	tail[fd] = ft_get_tail(tail[fd]);
	return (dest);
}
