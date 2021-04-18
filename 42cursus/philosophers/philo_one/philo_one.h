/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:41:17 by joopark           #+#    #+#             */
/*   Updated: 2021/04/18 16:32:14 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# ifndef PHILO_THINKING
#  define PHILO_THINKING 110
# endif
# ifndef PHILO_GET_FORK
#  define PHILO_GET_FORK 120
# endif
# ifndef PHILO_GET_FORK_ANOTHER
#  define PHILO_GET_FORK_ANOTHER 130
# endif
# ifndef PHILO_EATING
#  define PHILO_EATING 140
# endif
# ifndef PHILO_SLEEPING
#  define PHILO_SLEEPING 150
# endif
# ifndef PHILO_DIE
#  define PHILO_DIE 160
# endif
# ifndef PHILO_ATE_ALL
#  define PHILO_ATE_ALL 170
# endif

typedef struct s_arg
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philo_must_eat;
}					t_arg;

typedef struct s_relay
{
	int				*id;
	void			*obj;
}					t_relay;

typedef struct s_philo
{
	pthread_t		thread;
	struct timeval	gen_timer;
	pthread_mutex_t	fork_mutex;
	long			fsm_timer_exp;
	long			time_to_live_exp;
	long			eat_cnt;
	int				fork;
	int				fork_got;
	int				philo_id;
}					t_philo;

typedef struct s_philo_one
{
	t_arg			arg;
	t_philo			*philos;
	int				print;
	pthread_mutex_t	print_mutex;
	int				stop;
	pthread_mutex_t	stop_mutex;
	int				philo_least_eat;
	pthread_mutex_t	philo_least_eat_mutex;
}					t_philo_one;

int					ft_arg_parser(int argc, char *argv[], t_arg *arg);
int					ft_atoi(const char *str, int *value);
struct timeval		timer_start(void);
long				timer_stop(struct timeval time_start);
void				ft_printer(int status, int philo_id, struct timeval time);
void				*ft_philosopher(void *arg);
int					ft_philo_get_fork(int right, t_philo_one *p);
int					ft_philo_giveback_fork(int right, t_philo_one *p);
void				ft_set_fork_seq(int *first, int *second, int i, int len);
int					ft_get_fork(int i, t_philo *philo);
void				ft_giveback_fork_atomic(int i, int j, t_philo *philo);
int					ft_watchdog(int i, t_philo_one *p);
int					ft_philo_fsm(int status, int i, t_philo_one *p);
void				ft_philo_fsm_do(int status, int i, t_philo_one *p);
void				ft_printer_mutex(int status, int philo_id, t_philo_one *p);
#endif
