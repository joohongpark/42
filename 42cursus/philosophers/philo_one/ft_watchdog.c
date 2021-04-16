/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watchdog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:24:54 by joopark           #+#    #+#             */
/*   Updated: 2021/04/17 02:28:58 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_one.h>

int			ft_watchdog(int i, t_philo_one *p)
{
	pthread_mutex_lock(&(p->philo_least_eat_mutex));
	if (p->philo_least_eat == p->arg.philo_num)
	{
		ft_printer(5, 0, p->philos[i].gen_timer);
		p->philo_least_eat = -1;
	}
	pthread_mutex_unlock(&(p->philo_least_eat_mutex));
	if (p->philo_least_eat == -1)
		return (0);
	p->philos[i].time_to_live = timer_stop(p->philos[i].time_to_live_t);
	if (p->philos[i].time_to_live > p->arg.time_to_die * 1000L)
	{
		pthread_mutex_lock(&(p->mutex_stop));
		if (p->philo_all_live == 1)
		{
			ft_printer(4, i + 1, p->philos[i].gen_timer);
			p->philo_all_live = 0;
		}
		pthread_mutex_unlock(&(p->mutex_stop));
	}
	return (p->philo_all_live);
}
