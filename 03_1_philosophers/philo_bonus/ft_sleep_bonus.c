/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:12:52 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/28 11:54:15 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philo_sleep(t_one_philo *ph)
{
	ft_print_logs(ph, "is sleeping");
	ft_usleep_fix(ph->set->t_sleep);
}
