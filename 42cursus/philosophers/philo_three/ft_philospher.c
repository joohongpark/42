/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philospher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:55:39 by joopark           #+#    #+#             */
/*   Updated: 2021/04/23 00:16:52 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_three.h>

void	ft_waisting_time(unsigned long stop_t, int *stop)
{
	struct timeval	tmp;

	tmp = timer_start();
	while (stop_t > timer_stop(tmp) && *stop == 0)
		usleep(100);
}

void	ft_philo_cnt(t_philo_three *p)
{
	if (p->philo.eat_cnt != -1)
	{
		p->philo.eat_cnt++;
		if (p->philo.eat_cnt == p->arg.number_of_times_each_philo_must_eat)
			sem_post(p->sema.eat_cnt);
	}
}

void	ft_timer_mutex(sem_t *arg, struct timeval *t)
{
	sem_wait(arg);
	*t = timer_start();
	sem_post(arg);
}

sem_t	*ft_gen_sema(int num)
{
	char	buf[33];
	sem_t	*rtn;
	int		i;

	memset(buf, 0, 33);
	i = 0;
	while (i < 32)
	{
		if ((num & (1 << (31 - i))))
			buf[i] = '1';
		else
			buf[i] = '0';
		i++;
	}
	rtn = ft_sem_gen(buf, 1);
	return (rtn);
}

void	ft_philosopher(t_philo_three *p, int i)
{
	pthread_t	watchdog;

	p->philo.philo_id = i + 1;
	p->philo.time_to_live = timer_start();
	p->philo.cnt_mutex = ft_gen_sema(i);
	ft_timer_mutex(p->philo.cnt_mutex, &(p->philo.time_to_live));
	pthread_create(&watchdog, NULL, ft_watchdog, (void *)p);
	while (p->stop == 0)
	{
		sem_wait(p->sema.forks);
		ft_printer_mutex(PHILO_GET_FORK, i + 1, p);
		sem_wait(p->sema.forks);
		ft_printer_mutex(PHILO_EATING, i + 1, p);
		ft_timer_mutex(p->philo.cnt_mutex, &(p->philo.time_to_live));
		ft_waisting_time(p->arg.time_to_eat * 1000UL, &(p->stop));
		sem_post(p->sema.forks);
		sem_post(p->sema.forks);
		ft_printer_mutex(PHILO_SLEEPING, i + 1, p);
		ft_waisting_time(p->arg.time_to_sleep * 1000UL, &(p->stop));
		ft_printer_mutex(PHILO_THINKING, i + 1, p);
		ft_philo_cnt(p);
	}
	pthread_join(watchdog, NULL);
}
