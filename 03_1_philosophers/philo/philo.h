/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:59:25 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/29 00:25:05 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef long int		t_llint;
typedef pthread_mutex_t	t_mutex;

typedef struct s_fork
{
	int		last_by;
	t_mutex	mutex_last;
	t_mutex	mutex_usage;
}	t_fork;

typedef struct s_set
{
	t_llint		n_phs;
	t_llint		t_die;
	t_llint		t_eat;
	t_llint		t_sleep;
	int			must_eat;
	int			life;
	t_fork		*forks;
	t_mutex		mutex_print;
	t_mutex		mutex_life;
	t_mutex		global_mutex;
	pthread_t	thread_live;
}	t_set;

typedef struct s_one_philo
{
	int			name;
	int			num;
	t_llint		time_start;
	int			l_fork_id;
	int			r_fork_id;
	int			total_eat;
	t_set		*set;
	pthread_t	*thread_ph;
	t_mutex		mutex_eat;
	t_mutex		mutex_time;
}	t_one_philo;

typedef struct s_philos
{
	t_one_philo	*phs;
	t_set		*set;
}	t_philos;

int			ft_atoi(const char *str);

void		ft_print_die(t_one_philo *p);
void		ft_print(int out, char *s);
void		ft_print_logs(t_one_philo *p, char *str);
void		ft_philo_think(t_one_philo *p);
void		ft_philo_sleep(t_one_philo *ph);
void		ft_usleep_fix(unsigned long time);

void		ft_take_forks(t_one_philo *philo);

void		set_fork_last_taken_by(t_one_philo *philo, int fork_id);
void		wait_for_fork(t_one_philo *philo, int fork_id);

long int	ft_get_time_now(void);

void		ft_init_set(t_philos *philos, char **av);
void		ft_init_phs(t_one_philo *one_ph, int i, t_set *sett);

int			ft_check_arg(int ac, char **av);
t_philos	*ft_check_malloc(char **av);
void		*ft_check_live(void *philo);
int			ft_validate_life(t_set *sett);

void		ft_free_all(t_philos *phls);

#endif
