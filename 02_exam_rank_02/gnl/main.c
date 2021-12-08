#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		r;
	int		fd;
	char	*line;

	line = NULL;
	fd = open("text.txt", O_RDONLY);

	// r = get_next_line(&line, fd);
	// printf("%s\n", line);
	// printf("r: %d\n", r);
	// free(line);
	// line = NULL;

	// r = get_next_line(&line, fd);
	// printf("%s\n", line);
	// printf("r: %d\n", r);
	// free(line);
	// line = NULL;

	// r = get_next_line(&line, fd);
	// printf("%s\n", line);
	// printf("r: %d\n", r);
	// free(line);
	// line = NULL;

	// r = get_next_line(&line, fd);
	// printf("%s\n", line);
	// printf("r: %d\n", r);
	// free(line);
	// line = NULL;

	while ((r = get_next_line(&line, fd)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);
		free(line);
		line = NULL;
	close(fd);
	system("leaks get_next_line");
	return (0);
}