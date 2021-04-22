/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:41:17 by joopark           #+#    #+#             */
/*   Updated: 2021/04/22 23:01:08 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

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
	pthread_t		watchdog;
	struct timeval	gen_timer;
	struct timeval	time_to_live;
	long			fsm_timer_exp;
	int				philo_id;
	int				eat_cnt;
	sem_t			*cnt_mutex;
}					t_philo;

typedef struct s_sema
{
	sem_t			*forks;
	sem_t			*stop_mutex;
	sem_t			*eat_cnt_mutex;
}					t_sema;

typedef struct s_philo_two
{
	t_arg			arg;
	t_philo			*philos;
	t_sema			sema;
	int				stop;
	int				philo_least_eat;
}					t_philo_two;

int					ft_arg_parser(int argc, char *argv[], t_arg *arg);
int					ft_atoi(const char *str, int *value);
struct timeval		timer_start(void);
unsigned long		timer_stop(struct timeval time_start);
void				ft_printer(int status, int philo_id, struct timeval time);
void				ft_unblocking(sem_t *sem, int len);
void				*ft_watchdog(void *arg);
void				ft_printer_mutex(int status, int philo_id, t_philo_two *p);
void				ft_waisting_time(unsigned long stop_t, int *stop);
void				ft_philo_cnt(int i, t_philo_two	*p);
void				ft_timer_mutex(sem_t *arg, struct timeval *t);
void				*ft_philosopher(void *arg);
sem_t				*ft_sem_gen(char *name, int value);
void				ft_itoa_32(char *buf, int num);
#endif
