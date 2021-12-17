/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:07:52 by mlarra            #+#    #+#             */
/*   Updated: 2021/12/17 22:10:53 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

// (school21) gcc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
// (home) gcc -I /Users/eugenia/C/school21/02_1_fdf/minilibx_macos main.c -L /Users/eugenia/C/school21/02_1_fdf/minilibx_macos -lmlx -framework OpenGL -framework AppKit
// gcc -I /Users/eugenia/C/school21/02_1_fdf/minilibx_macos /Users/eugenia/C/school21/02_1_fdf/00_libft main.c map.c -L /Users/eugenia/C/school21/02_1_fdf/minilibx_macos -lmlx /Users/eugenia/C/school21/02_1_fdf/00_libft -lft  -framework OpenGL -framework AppKit

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// int	deal_key(int key, void *param)
// {
// 	ft_putchar('O');
// 	return (0);
// }

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		*arr_z;
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			return (0);
		arr_z = NULL;
		if (ft_check_map(&arr_z, argv[1], data))
		{
			mlx_ptr = mlx_init();
			win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
			mlx_pixel_put(mlx_ptr, win_ptr, 100, 200, 0xFFFFFF);
			// mlx_key_hook(win_ptr, deal_key, (void *)0);
			mlx_loop(mlx_ptr);
		}
	}
	else
	{
		write(2, "use file of type .fdf", 21);
		return (0);
	}
}
