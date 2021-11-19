/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:14:25 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/17 12:34:45 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE -1
#endif

char	*ft_reading_buf(int fd, char *buf, char *tail)
{
	int	nbytes;

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
	static char	*tail;

	if (fd < 0 || BUFFER_SIZE < 1)
		return ((void *)0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ((void *)0);
	tail = ft_reading_buf(fd, buf, tail);
	if (!tail || tail[0] == '\0')
	{
		free((void *)tail);
		tail = 0;
		return ((void *)0);
	}
	dest = ft_get_line(tail);
	if (!dest || dest[0] == '\0')
	{
		free ((void *)dest);
		return ((void *)0);
	}
	tail = ft_get_tail(tail);
	return (dest);
}
