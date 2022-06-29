/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:59:03 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/29 00:43:26 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_check_arg(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 5 || ac > 6)
		return (1);
	i = 0;
	while (av[++i])
	{
		if (ft_atoi(av[i]) <= 0)
			return (1);
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '+')
				return (1);
		}
	}
	return (0);
}

void	*ft_check_live(void *philo)
{
	t_one_philo	*ph;
	t_llint		time_start;

	ph = philo;
	while (1)
	{
		if (ft_validate_life(ph->set) == 0)
			return (NULL);
		sem_wait(ph->sem_time);
		time_start = ph->time_start;
		sem_post(ph->sem_time);
		if (ft_get_time_now() - time_start > ph->set->t_die)
		{
			sem_wait(ph->set->living);
			ph->set->life = 0;
			sem_post(ph->set->living);
			ft_print_die(ph);
			sem_post(ph->set->sem_die);
			return (NULL);
		}
	}
	return (NULL);
}

void	*ft_eats(void *phils)
{
	t_one_philo	*phs;
	t_set		*set;
	int			i;

	phs = phils;
	set = phs[0].set;
	if (set->must_eat == -1)
		return (NULL);
	phs = phils;
	i = -1;
	while (++i < set->n_phs)
		sem_wait(phs[i].sem_eat);
	sem_post(phs->set->sem_die);
	return (NULL);
}
