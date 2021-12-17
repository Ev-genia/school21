/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:07:52 by mlarra            #+#    #+#             */
/*   Updated: 2021/12/17 21:28:51 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include "/Users/eugenia/C/school21/02_1_fdf/minilibx_macos/mlx.h"
# include <fcntl.h>
# include "gnl/get_next_line.h"

# include "libft.h"

typedef struct s_data
{
	int	x;
	int	y;
// 	int	z;
}	t_data;

int	**ft_check_map(int **arr_z, char *file_name, t_data *data);

#endif