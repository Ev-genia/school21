/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:04:45 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/28 22:42:09 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <signal.h>

typedef long int	t_llint;
typedef struct s_set
{
	t_llint		n_phs;
	t_llint		t_die;
	t_llint		t_eat;
	t_llint		t_sleep;
	int			must_eat;
	int			life;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*living;
	sem_t		*sem_die;
	sem_t		**sem_table;
	sem_t		*sem_start;
	sem_t		*sem_end;

}	t_set;

typedef struct s_one_philo
{
	int			name;
	int			num;
	t_llint		time_start;
	int			total_eat;
	sem_t		*sem_eat;
	sem_t		*sem_time;
	t_set		*set;
	pid_t		pid_num;
	pthread_t	thread_monitor;
}	t_one_philo;

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);

// ft_print.c
void		ft_print(int out, char *s);
void		ft_print_die(t_one_philo *p);
void		ft_print_logs(t_one_philo *p, char *str);
int			ft_validate_life(t_set *sett);

//ft_init_bonus.c
void		ft_init_set(t_one_philo *philos, char **av);
void		ft_usleep_fix(unsigned long time);
t_one_philo	*ft_init(char **av, t_set *set);

//ft_utils_bonus.c
long int	ft_get_time_now(void);

// ft_check_bonus.c 
void		*ft_check_live(void *philos);
int			ft_check_arg(int ac, char **av);
t_one_philo	*ft_check_malloc(char **av);
void		*ft_eats(void *phils);

// ft_sleep_bonus.c  
void		ft_philo_sleep(t_one_philo *ph);

// ft_free_bonus.c 
void		ft_free_all(t_one_philo *phil);
void		*ft_wait(void *philos);

char		*make_semaphore_name(int num);

int			ft_one_philo(t_one_philo *philo);

#endif