/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:12:57 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/28 14:59:28 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sem_unlink_close(char *sem_name, sem_t *sem)
{
	sem_unlink(sem_name);
	sem_close(sem);
}

void	ft_free_all(t_one_philo *phil)
{
	int		i;
	char	*sem_name;

	i = -1;
	while (++i < phil[0].set->n_phs)
		kill(phil[i].pid_num, SIGTERM);
	ft_sem_unlink_close("sem_print", phil[0].set->print);
	ft_sem_unlink_close("sem_forks", phil[0].set->forks);
	ft_sem_unlink_close("sem_living", phil[0].set->living);
	ft_sem_unlink_close("sem_died", phil[0].set->sem_die);
	ft_sem_unlink_close("sem_start", phil[0].set->sem_start);
	ft_sem_unlink_close("sem_end", phil[0].set->sem_end);
	i = -1;
	while (++i < phil[0].set->n_phs)
	{
		sem_close(phil[0].set->sem_table[i]);
		sem_name = make_semaphore_name(i);
		sem_unlink(sem_name);
		free(sem_name);
		ft_sem_unlink_close("sem_time", phil[i].sem_time);
		ft_sem_unlink_close("sem_eat", phil[i].sem_eat);
	}
	free(phil[0].set->sem_table);
	free(phil);
}

void	*ft_wait(void *philos)
{
	t_one_philo	*phs;
	t_set		*sett;
	int			i;
	int			status;

	phs = philos;
	sett = phs[0].set;
	i = -1;
	while (waitpid(-1, &status, 0) > 0)
	{
		if (WEXITSTATUS(status))
		{
			while (++i < sett->n_phs)
				kill(phs[i].pid_num, SIGTERM);
		}
	}
	return (NULL);
}
