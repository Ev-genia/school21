/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:06:39 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/28 17:23:12 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*open_semaphore(char *name, int val)
{
	sem_t	*i;

	sem_unlink(name);
	i = sem_open(name, O_CREAT, 0644, val);
	return (i);
}

char	*make_semaphore_name(int num)
{
	char	*temp;
	char	*sem_name;

	temp = ft_itoa(num);
	sem_name = ft_strjoin("queue", temp);
	free(temp);
	return (sem_name);
}

t_one_philo	*ft_init_phs(t_set *set)
{
	t_one_philo	*philos;
	int			i;

	philos = malloc(sizeof(t_one_philo) * set->n_phs);
	if (!philos)
	{
		free(set->sem_table);
		return (NULL);
	}
	i = -1;
	while (++i < set->n_phs)
	{
		philos[i].num = i;
		philos[i].name = philos[i].num + 1;
		philos[i].total_eat = 0;
		philos[i].set = set;
		philos[i].sem_eat = open_semaphore("sem_eat", 0);
		philos[i].sem_time = open_semaphore("sem_time", 1);
		philos[i].time_start = ft_get_time_now();
	}
	return (philos);
}

void	ft_open_sems(t_set *set)
{
	set->print = open_semaphore("sem_print", 1);
	set->forks = open_semaphore("sem_forks", set->n_phs);
	set->living = open_semaphore("sem_living", 1);
	set->sem_die = open_semaphore("sem_died", 0);
	set->sem_start = open_semaphore("sem_start", 0);
	set->sem_end = open_semaphore("sem_end", 0);
}

t_one_philo	*ft_init(char **av, t_set *set)
{
	int			i;
	char		*sem_name;

	set->n_phs = ft_atoi(av[1]);
	set->t_die = ft_atoi(av[2]);
	set->t_eat = ft_atoi(av[3]);
	set->t_sleep = ft_atoi(av[4]);
	if (av[5])
		set->must_eat = ft_atoi(av[5]);
	else
		set->must_eat = -1;
	set->life = 1;
	ft_open_sems(set);
	set->sem_table = malloc(sizeof(sem_t *) * set->n_phs);
	if (!set->sem_table)
		return (NULL);
	i = -1;
	while (++i < set->n_phs)
	{
		sem_name = make_semaphore_name(i);
		set->sem_table[i] = open_semaphore(sem_name, i % 2);
		free(sem_name);
	}
	return (ft_init_phs(set));
}
