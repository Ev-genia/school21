/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:02:37 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/17 17:35:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"
#include "get_next_line_bonus.c"
#include "get_next_line_utils_bonus.c"

int	main()
{
	int		fd1;
	int		fd2;
	char	*str;

	fd1 = open("fd1.txt", O_RDONLY);
	fd2 = open("fd2.txt", O_RDONLY);
	str = get_next_line(fd1);
	printf("%s", str);
	free(str);
	str = get_next_line(fd2);
	printf("%s", str);
	free(str);
	str = get_next_line(fd1);
	printf("%s", str);
	free(str);
	str = get_next_line(fd2);
	printf("%s", str);
	free(str);
	close(fd1);
	close(fd2);
/*	while ((line = get_next_line(0)))
	{
		printf("%s", line);
		free(line);
	}*/
	return (0);
}
