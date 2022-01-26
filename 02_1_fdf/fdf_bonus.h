/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:04:38 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/19 15:33:47 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "00_libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx.h"

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
	int		shift_z;
	int		color;
	float	angle;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	int		w_width;
	int		w_height;
}	t_data;

int		ft_check_map(char *filename);
int		ft_get_height(char *filename);
int		ft_get_width(char *line);
void	ft_exit_arg(void);
void	ft_exit_fd(void);
void	ft_exit_map(void);
void	ft_exit_memory(void);
void	ft_alloc_memory(t_data *data, char *filename);
void	ft_fill_elems(t_data *data, char *filename);
void	ft_isometric(t_elem *elem, t_data *data);
int		ft_draw(t_data *data);
int		ft_draw_XoY(t_data *data);
void	ft_init_data(t_data *data);
void	ft_scale_coordinate(t_elem *elem1, t_elem *elem2, t_data *data);
void	ft_shift_coordinate(t_elem *elem1, t_elem *elem2, t_data *data);
int		ft_choise_color(t_elem elem1, t_elem elem2);
int		deal_key(int key, t_data *data);
int		close_win_x(t_data *data);
void	ft_get_addr(t_data *data);

#endif
