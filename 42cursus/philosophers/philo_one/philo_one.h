/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:41:17 by joopark           #+#    #+#             */
/*   Updated: 2021/04/17 19:26:17 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_ONE_H
# define FT_PHILO_ONE_H

// 공통
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

# ifndef PHILO_THINKING
#  define PHILO_THINKING 110
# endif
# ifndef PHILO_GET_FORK
#  define PHILO_GET_FORK 120
# endif
# ifndef PHILO_EATING
#  define PHILO_EATING 130
# endif
# ifndef PHILO_SLEEPING
#  define PHILO_SLEEPING 140
# endif
# ifndef PHILO_DIE
#  define PHILO_DIE 150
# endif
# ifndef PHILO_ATE_ALL
#  define PHILO_ATE_ALL 160
# endif

typedef struct		s_arg
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philo_must_eat;
}					t_arg;

typedef struct		s_relay
{
	int				*id;
	void			*obj;
}					t_relay;

int					ft_arg_parser(int argc, char *argv[], t_arg *arg);
int					ft_atoi(const char *str, int *value);
struct timeval		timer_start(void);
long				timer_stop(struct timeval time_start);
void				ft_printer(int status, int philo_id, struct timeval time);
// 따로

typedef struct		s_philo
{
	pthread_t		thread;
	struct timeval	gen_timer;
	struct timeval	fsm_timer_t;
	struct timeval	time_to_live_t;
	pthread_mutex_t	fork_mutex;
	long			fsm_timer;
	long			time_to_live;
	long			eat_cnt;
	int				fork;
	int				fork_got;
	int				philo_id;
}					t_philo;

typedef struct		s_philo_one
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

void				*ft_philosopher(void *arg);
int		ft_philo_get_fork(int right, t_philo_one *p);
int		ft_philo_giveback_fork(int right, t_philo_one *p);
void		ft_set_fork_seq(int *first, int *second, int i, int len);
int			ft_get_fork_atomic(int *fork, pthread_mutex_t *mutex);
int			ft_giveback_fork_atomic(int *fork, pthread_mutex_t *mutex);
int			ft_watchdog(int i, t_philo_one *p);
int			ft_philo_fsm(int status, int i, t_philo_one *p);
void			ft_philo_fsm_do(int status, int i, t_philo_one *p);
#endif