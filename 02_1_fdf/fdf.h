/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:07:52 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/10 11:40:06 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include "/Users/eugenia/C/school21/02_1_fdf/minilibx_macos/mlx.h"
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include <math.h>

# include "libft.h"

typedef struct s_coordinate
{
	float	x;
	float	y;
	int		z;
}	t_coordinate;


typedef struct s_data
{
	int				width;//x;
	int				height;//y;
// 	int	z;
	int				scale;
	int				color;
	t_coordinate	*arr_z;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

// int		**ft_check_map(int **arr_z, char *file_name, t_data *data);
t_coordinate		**ft_check_map(char *file_name, t_data *data);
// void	draw_line(float x1, float y1, float x2, float y2, t_data *data);
// void	draw_map(t_data *data, int *arr_z);
void	draw_map(t_data *data);

#endif