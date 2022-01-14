/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:04:38 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/14 18:22:24 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
//?
# include "00_libft/libft.h"
# include "gnl/get_next_line.h"
// home
# include "/Users/eugenia/C/school21/02_1_fdf/minilibx_macos/mlx.h"
// school
// # include "mlx.h"

typedef struct s_elem
{
	float	x;
	float	y;
	float	z;
}	t_elem;

typedef struct s_data
{
	t_elem	*elems;
	int		width;
	int		height;
	int		scale;
	int		shift_x;
	int		shift_y;
	int		color;
	float	angle;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;

	int		w_width;
	int		w_height;
}	t_data;

#endif
