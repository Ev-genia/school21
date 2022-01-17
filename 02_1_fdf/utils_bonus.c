/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:53:41 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/17 18:54:24 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf_bonus.h"

void	ft_scale_coordinate(t_elem *elem1, t_elem *elem2, t_data *data)
{
	elem1->x *= data->scale;
	elem1->y *= data->scale;
	elem2->x *= data->scale;
	elem2->y *= data->scale;
}

void	ft_shift_coordinate(t_elem *elem1, t_elem *elem2, t_data *data)
{
	elem1->x += data->shift_x;
	elem1->y += data->shift_y;
	elem2->x += data->shift_x;
	elem2->y += data->shift_y;
}

int	ft_choise_color(t_elem elem1, t_elem elem2)
{
	if (elem1.z > 0 || elem2.z > 0)
		return (0xFFFFFF);
	else
		return (0x0000ff);
}