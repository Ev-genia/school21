/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:06:15 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/28 17:28:31 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long int	ft_get_time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long int) time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep_fix(unsigned long time)
{
	unsigned long	t;

	t = ft_get_time_now();
	while (ft_get_time_now() - t < time)
		usleep(1);
}
