/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watchdog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:24:54 by joopark           #+#    #+#             */
/*   Updated: 2021/04/17 15:09:58 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_one.h>

int			ft_watchdog(int i, t_philo_one *p)
{
	int		flag;

	flag = 0;
	pthread_mutex_lock(&(p->philo_least_eat_mutex));
	if (p->philo_least_eat == p->arg.philo_num)
		p->stop = 0;
	pthread_mutex_unlock(&(p->philo_least_eat_mutex));
	p->philos[i].time_to_live = timer_stop(p->philos[i].time_to_live_t);
	if (p->philos[i].time_to_live > p->arg.time_to_die * 1000L)
	{
		pthread_mutex_lock(&(p->stop_mutex));
		p->stop = 0;
		pthread_mutex_unlock(&(p->stop_mutex));
		flag = 1;
	}
	return (p->stop);
}
