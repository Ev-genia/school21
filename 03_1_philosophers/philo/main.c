/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:59:31 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/29 00:36:39 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_forks(t_one_philo *philo)
{
	if (philo->set->n_phs == 1)
	{
		ft_print_logs(philo, "has taken a fork");
		while (ft_validate_life(philo->set) == 1)
			usleep(1);
		return ;
	}
	wait_for_fork(philo, philo->l_fork_id);
	pthread_mutex_lock(&philo->set->forks[philo->l_fork_id].mutex_usage);
	ft_print_logs(philo, "has taken a fork");
	wait_for_fork(philo, philo->r_fork_id);
	pthread_mutex_lock(&philo->set->forks[philo->r_fork_id].mutex_usage);
	ft_print_logs(philo, "has taken a fork");
	set_fork_last_taken_by(philo, philo->l_fork_id);
	set_fork_last_taken_by(philo, philo->r_fork_id);
	pthread_mutex_lock(&philo->mutex_time);
	philo->time_start = ft_get_time_now();
	pthread_mutex_unlock(&philo->mutex_time);
	ft_print_logs(philo, "is eating");
	ft_usleep_fix(philo->set->t_eat);
	pthread_mutex_lock(&philo->mutex_eat);
	philo->total_eat++;
	pthread_mutex_unlock(&philo->mutex_eat);
	pthread_mutex_unlock(&philo->set->forks[philo->r_fork_id].mutex_usage);
	pthread_mutex_unlock(&philo->set->forks[philo->l_fork_id].mutex_usage);
}

void	*ft_start_philo(void *p)
{
	t_one_philo	*ph;

	ph = p;
	pthread_mutex_lock(&ph->mutex_time);
	ph->time_start = ft_get_time_now();
	pthread_mutex_unlock(&ph->mutex_time);
	while (1)
	{
		if (ft_validate_life(ph->set) == 0)
			return (NULL);
		ft_take_forks(ph);
		if (ft_validate_life(ph->set) == 0)
			return (NULL);
		ft_philo_sleep(ph);
		ft_print_logs(ph, "is thinking");
	}
	return (NULL);
}

void	ft_create_threads(t_philos *ps)
{
	int			i;
	int			rez;

	i = 1;
	while (i < ps->set->n_phs)
	{
		rez = pthread_create(ps->phs[i].thread_ph, NULL,
				ft_start_philo, &ps->phs[i]);
		if (rez != 0)
			return (ft_print(2, "pthread_create_err"));
		i += 2;
	}
	ft_usleep_fix(ps->set->t_eat);
	i = 0;
	while (i < ps->set->n_phs)
	{
		rez = pthread_create(ps->phs[i].thread_ph, NULL,
				ft_start_philo, &ps->phs[i]);
		if (rez != 0)
			return (ft_print(2, "pthread_create_err"));
		i += 2;
	}
	pthread_create(&ps->set->thread_live, NULL, ft_check_live, ps);
}

void	ft_mutex_destroy(t_philos *p)
{
	int	i;

	i = -1;
	while (++i < p->set->n_phs)
	{
		pthread_mutex_destroy(&p->set->forks[i].mutex_last);
		pthread_mutex_destroy(&p->set->forks[i].mutex_usage);
		pthread_mutex_destroy(&p->phs[i].mutex_eat);
		pthread_mutex_destroy(&p->phs[i].mutex_time);
	}
	pthread_mutex_destroy(&p->set->mutex_print);
	pthread_mutex_destroy(&p->set->mutex_life);
}

int	main(int argc, char **argv)
{
	t_philos	*phils;
	int			i;

	if (ft_check_arg(argc, argv) != 0)
	{
		ft_print(2, "Error argumens\n");
		return (1);
	}
	phils = ft_check_malloc(argv);
	if (phils == NULL)
	{
		ft_print(2, "Malloc error\n");
		return (1);
	}
	ft_init_set(phils, argv);
	ft_create_threads(phils);
	i = -1;
	while (++i < phils->set->n_phs)
		pthread_join(*phils->phs[i].thread_ph, NULL);
	pthread_join(phils->set->thread_live, NULL);
	ft_mutex_destroy(phils);
	ft_free_all(phils);
	return (0);
}
