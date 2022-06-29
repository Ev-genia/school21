/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:38:07 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/28 22:41:35 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_one_philo(t_one_philo *philo)
{
	if (philo->set->n_phs == 1)
	{
		ft_print_logs(philo, "has taken a fork");
		while (ft_validate_life(philo->set) == 1)
			usleep(1);
		return (1);
	}
	return (0);
}
