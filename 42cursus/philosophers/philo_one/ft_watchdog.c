/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watchdog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:24:54 by joopark           #+#    #+#             */
/*   Updated: 2021/04/18 03:30:22 by joopark          ###   ########.fr       */
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
	if (timer_stop(p->philos[i].gen_timer) > p->philos[i].time_to_live_exp)
	{
		pthread_mutex_lock(&(p->stop_mutex));
		p->stop = 0;
		pthread_mutex_unlock(&(p->stop_mutex));
		flag = 1;
	}
	return (p->stop);
}
