/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:05:07 by mlarra            #+#    #+#             */
/*   Updated: 2022/05/27 14:55:18 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_sleep(t_one_philo *ph)
{
	ft_print_logs(ph, "is sleeping");
	ft_usleep_fix(ph->set->t_sleep);
}
