/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:01:40 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/29 00:37:06 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_die(t_one_philo *p)
{
	t_llint	time;

	pthread_mutex_lock(&p->set->mutex_print);
	time = ft_get_time_now();
	printf("%ld %d died\n", time, p->name);
	pthread_mutex_unlock(&p->set->mutex_print);
}

void	ft_print(int out, char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(out, &s[i], 1);
}

int	ft_validate_life(t_set *sett)
{
	int	validate;

	pthread_mutex_lock(&sett->mutex_life);
	validate = sett->life;
	pthread_mutex_unlock(&sett->mutex_life);
	return (validate);
}

void	ft_print_logs(t_one_philo *p, char *str)
{
	t_llint	time;

	if (ft_validate_life(p->set) == 0)
		return ;
	time = ft_get_time_now();
	pthread_mutex_lock(&p->set->mutex_print);
	printf("%ld %d %s\n", time, p->name, str);
	pthread_mutex_unlock(&p->set->mutex_print);
}
