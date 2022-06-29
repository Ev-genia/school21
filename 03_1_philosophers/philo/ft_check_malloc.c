/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:04:02 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/28 22:18:41 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philos	*ft_malloc_phs(char **av, t_philos *p)
{
	t_philos	*phls;

	phls = p;
	phls->phs = malloc(sizeof(t_one_philo) * ft_atoi(av[1]));
	if (!phls->phs)
	{
		free(phls);
		free(phls->set);
		free(phls->set->forks);
		return (NULL);
	}
	return (phls);
}

t_philos	*ft_malloc_thread(char **av, t_philos *p)
{
	int			i;
	t_philos	*phls;

	phls = ft_malloc_phs(av, p);
	if (phls == NULL)
		return (NULL);
	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		phls->phs[i].thread_ph = malloc(sizeof(pthread_t));
		if (!phls->phs[i].thread_ph)
		{
			free(phls->phs);
			free(phls->set->forks);
			free(phls->set);
			free(phls);
			return (NULL);
		}
	}
	return (phls);
}

t_philos	*ft_check_malloc(char **av)
{
	t_philos	*phls;

	phls = malloc(sizeof(t_philos));
	if (!phls)
		return (NULL);
	phls->set = malloc(sizeof(t_set));
	if (!phls->set)
	{
		free(phls);
		return (NULL);
	}
	phls->set->forks = malloc(sizeof(t_fork) * ft_atoi(av[1]));
	if (!phls->set->forks)
	{
		free(phls);
		free(phls->set);
		return (NULL);
	}
	phls = ft_malloc_thread(av, phls);
	if (phls == NULL)
		return (NULL);
	return (phls);
}
