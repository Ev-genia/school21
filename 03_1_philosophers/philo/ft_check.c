/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:30:34 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/29 00:19:16 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ft_is_must_eat(t_one_philo *p)
{
	if (p->set->must_eat == -1)
		return (1);
	if (p->total_eat < p->set->must_eat)
		return (1);
	return (0);
}

int	ft_check_die(t_one_philo *p)
{
	t_llint	time;

	pthread_mutex_lock(&p->mutex_time);
	time = ft_get_time_now();
	if (time - p->time_start > p->set->t_die)
	{
		pthread_mutex_unlock(&p->mutex_time);
		return (1);
	}
	pthread_mutex_unlock(&p->mutex_time);
	return (0);
}

int	ft_all_eat(t_philos *ph)
{
	int	i;

	i = 0;
	while (i < ph->set->n_phs)
	{
		pthread_mutex_lock(&ph->phs[i].mutex_eat);
		if (ph->phs[i].total_eat < ph->set->must_eat)
		{
			pthread_mutex_unlock(&ph->phs[i].mutex_eat);
			return (0);
		}
		pthread_mutex_unlock(&ph->phs[i].mutex_eat);
		i++;
	}
	return (1);
}

void	*ft_check_live(void *philos)
{
	t_philos	*ph;
	int			i;

	ph = philos;
	while (1)
	{
		i = 0;
		while (i < ph->set->n_phs)
		{
			if (ft_check_die(&ph->phs[i])
				|| (ph->set->must_eat != -1 && ft_all_eat(ph)))
			{
				pthread_mutex_lock(&ph->set->mutex_life);
				ph->set->life = 0;
				pthread_mutex_unlock(&ph->set->mutex_life);
				if (ft_check_die(&ph->phs[i]))
					ft_print_die(&ph->phs[i]);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
