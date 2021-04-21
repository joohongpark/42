/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:41:17 by joopark           #+#    #+#             */
/*   Updated: 2021/04/21 22:05:37 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

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

typedef struct s_philo
{
	struct timeval	gen_timer;
	struct timeval	time_to_live;
	long			fsm_timer_exp;
	int				philo_id;
	int				eat_cnt;
}					t_philo;

typedef struct s_sema
{
	sem_t			*forks;
	sem_t			*stop_mutex;
	sem_t			*print_mutex;
	sem_t			*eat_cnt;
	sem_t			*main_watchdog;
}					t_sema;

typedef struct s_philo_three
{
	t_arg			arg;
	t_philo			philo;
	t_sema			sema;
	pid_t			*pids;
	int				stop;
	int				die_id;
}					t_philo_three;

int					ft_arg_parser(int argc, char *argv[], t_arg *arg);
int					ft_atoi(const char *str, int *value);
struct timeval		timer_start(void);
long				timer_stop(struct timeval time_start);
void				ft_printer(int status, int philo_id, struct timeval time);
void				ft_unblocking(sem_t *sem, int len);
void				*ft_watchdog(void *arg);
void	*ft_watchdog_die(void *arg);
void	*ft_watchdog_eat(void *arg);
void				ft_printer_mutex(int status, int philo_id, t_philo_three *p);
void				ft_waisting_time(long stop_t, int *stop);
void				ft_philo_cnt(t_philo_three *p);
void				ft_philosopher(t_philo_three *p, int i);
sem_t				*ft_sem_gen(char *name, int value);
int	ft_philo_init(t_philo_three *arg);
#endif
