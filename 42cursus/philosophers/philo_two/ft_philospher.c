/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philospher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:55:39 by joopark           #+#    #+#             */
/*   Updated: 2021/04/22 23:31:10 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_two.h>

void	ft_waisting_time(unsigned long stop_t, int *stop)
{
	struct timeval	tmp;

	tmp = timer_start();
	while (stop_t > timer_stop(tmp) && *stop == 0)
		usleep(100);
}

void	ft_philo_cnt(int i, t_philo_two	*p)
{
	if (p->philos[i].eat_cnt != -1)
	{
		p->philos[i].eat_cnt++;
		if (p->philos[i].eat_cnt == p->arg.number_of_times_each_philo_must_eat)
		{
			sem_wait(p->sema.eat_cnt_mutex);
			if (p->stop == 0)
				p->philo_least_eat = p->philo_least_eat + 1;
			sem_post(p->sema.eat_cnt_mutex);
		}
	}
}

void	ft_timer_mutex(sem_t *arg, struct timeval *t)
{
	sem_wait(arg);
	*t = timer_start();
	sem_post(arg);
}

void	*ft_philosopher(void *arg)
{
	int			i;
	t_philo_two	*p;

	i = *((*((t_relay *)arg)).id) - 1;
	p = (t_philo_two *)((*((t_relay *)arg)).obj);
	p->philos[i].gen_timer = timer_start();
	ft_timer_mutex(p->philos[i].cnt_mutex, &(p->philos[i].time_to_live));
	pthread_create(&(p->philos[i].watchdog), NULL, ft_watchdog, arg);
	while (p->stop == 0)
	{
		sem_wait(p->sema.forks);
		ft_printer_mutex(PHILO_GET_FORK, i + 1, p);
		sem_wait(p->sema.forks);
		ft_timer_mutex(p->philos[i].cnt_mutex, &(p->philos[i].time_to_live));
		ft_printer_mutex(PHILO_EATING, i + 1, p);
		ft_waisting_time(p->arg.time_to_eat * 1000UL, &(p->stop));
		sem_post(p->sema.forks);
		sem_post(p->sema.forks);
		ft_printer_mutex(PHILO_SLEEPING, i + 1, p);
		ft_waisting_time(p->arg.time_to_sleep * 1000UL, &(p->stop));
		ft_printer_mutex(PHILO_THINKING, i + 1, p);
		ft_philo_cnt(i, p);
	}
	pthread_join(p->philos[i].watchdog, NULL);
	return (NULL);
}
