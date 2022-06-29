/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:22:49 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/28 22:23:10 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_fork_last_taken_by(t_one_philo *philo, int fork_id)
{
	pthread_mutex_lock(&philo->set->forks[fork_id].mutex_last);
	philo->set->forks[fork_id].last_by = philo->name;
	pthread_mutex_unlock(&philo->set->forks[fork_id].mutex_last);
}

void	wait_for_fork(t_one_philo *philo, int fork_id)
{
	int	fork_last_taken_by;

	while (1)
	{
		pthread_mutex_lock(&philo->set->forks[fork_id].mutex_last);
		fork_last_taken_by = philo->set->forks[fork_id].last_by;
		pthread_mutex_unlock(&philo->set->forks[fork_id].mutex_last);
		if (fork_last_taken_by != philo->name)
			return ;
		usleep(100);
	}
}
