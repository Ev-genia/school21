#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
//?
# include "00_libft/libft.h"
# include "gnl/get_next_line.h"
# include "/Users/eugenia/C/school21/02_1_fdf/minilibx_macos/mlx.h"

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
	int		shift;
	int		color;
	float	angle;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;


#endif