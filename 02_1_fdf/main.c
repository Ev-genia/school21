/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:07:52 by mlarra            #+#    #+#             */
/*   Updated: 2021/12/15 10:18:12 by mlarra           ###   ########.fr       */
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



int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		**arr_z;
printf("test");
printf("ft_check_map(&arr_z): %d\n", ft_check_map(&arr_z));
	if (ft_check_map(&arr_z) == 1)
	{
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx 42");
		mlx_pixel_put(mlx_ptr, win_ptr, 500, 250, 0xFFFFFF);
		// mlx_key_hook(win_ptr, deal_key, (void *)0);
		mlx_loop(mlx_ptr);
	}
	else
	{
		return (ft_check_map(&arr_z));
	}
}
