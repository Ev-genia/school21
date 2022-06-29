/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:04:29 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/29 01:04:59 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_take_forks(t_one_philo *philo)
{
	int	current_index;
	int	passed_index;

	if (ft_one_philo(philo))
		return ;
	current_index = philo->num;
	sem_wait(philo->set->sem_table[current_index]);
	sem_wait(philo->set->forks);
	ft_print_logs(philo, "has taken a fork");
	sem_wait(philo->set->forks);
	ft_print_logs(philo, "has taken a fork");
	sem_wait(philo->sem_time);
	philo->time_start = ft_get_time_now();
	sem_post(philo->sem_time);
	ft_print_logs(philo, "is eating");
	usleep(philo->set->t_eat * 1000);
	sem_wait(philo->sem_time);
	philo->total_eat++;
	sem_post(philo->sem_time);
	sem_post(philo->set->forks);
	sem_post(philo->set->forks);
	passed_index = (current_index + 1) % philo->set->n_phs;
	sem_post(philo->set->sem_table[passed_index]);
}

void	*ft_end(void *ph)
{
	t_one_philo	*p;

	p = ph;
	sem_wait(p->set->sem_end);
	sem_wait(p->set->living);
	p->set->life = 0;
	sem_post(p->set->living);
	return (NULL);
}

void	*ft_start_philo(t_one_philo *ph)
{
	int			total_eat;
	pthread_t	ph_end;

	pthread_create(&ph_end, NULL, ft_end, ph);
	pthread_detach(ph_end);
	sem_wait(ph->sem_time);
	ph->time_start = ft_get_time_now();
	sem_post(ph->sem_time);
	while (1)
	{
		if (ft_validate_life(ph->set) == 0)
			return (NULL);
		ft_take_forks(ph);
		if (ft_validate_life(ph->set) == 0)
			return (NULL);
		sem_wait(ph->sem_time);
		total_eat = ph->total_eat;
		sem_post(ph->sem_time);
		if (ph->set->must_eat != -1 && total_eat == ph->set->must_eat)
			sem_post(ph->sem_eat);
		ft_philo_sleep(ph);
		ft_print_logs(ph, "is thinking");
	}
	return (NULL);
}

void	ft_create_philo(t_one_philo *philos)
{
	int			i;
	t_set		*set;
	pthread_t	eats;
	pthread_t	ph_live;

	set = philos[0].set;
	i = -1;
	while (++i < set->n_phs)
	{
		philos[i].pid_num = fork();
		if (philos[i].pid_num == 0)
		{
			sem_wait(philos[i].set->sem_start);
			pthread_create(&ph_live, NULL, ft_check_live, &philos[i]);
			pthread_detach(ph_live);
			ft_start_philo(&philos[i]);
			exit(0);
		}
	}
	i = -1;
	while (++i < set->n_phs)
		sem_post(philos[i].set->sem_start);
	pthread_create(&eats, NULL, ft_eats, philos);
	pthread_detach(eats);
}

int	main(int argc, char **argv)
{
	t_one_philo	*phils;
	t_set		set;
	int			i;

	if (ft_check_arg(argc, argv) != 0)
	{
		ft_print(2, "Error argumens\n");
		return (1);
	}
	phils = ft_init(argv, &set);
	if (phils == NULL)
	{
		ft_print(2, "Error malloc\n");
		return (1);
	}
	ft_create_philo(phils);
	sem_wait(set.sem_die);
	i = -1;
	while (++i < set.n_phs)
		sem_post(set.sem_end);
	ft_wait(phils);
	ft_free_all(phils);
	return (0);
}
