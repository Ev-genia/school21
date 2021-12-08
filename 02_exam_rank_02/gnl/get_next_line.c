#include "get_next_line.h"

int	get_next_line(char **line, int fd)
{
	int		n;
	int		i;
	char	*buf;

	buf = malloc(sizeof(char) * 10000);
	if (!buf)
		return (-1);
	i = 0;
	while ((n = read(fd, &buf[i], 1) == 1) && buf[i] != '\n' && buf[i] != '\0')
		i++;
	buf[i] = '\0';
	*line = buf;
	return (n);
}