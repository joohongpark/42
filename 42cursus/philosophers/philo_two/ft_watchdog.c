/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watchdog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:24:54 by joopark           #+#    #+#             */
/*   Updated: 2021/04/20 12:55:48 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_two.h>

void	ft_unblocking(sem_t *sem, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		sem_post(sem);
		i++;
	}
}

void	*ft_watchdog(void *arg)
{
	int			i;
	t_philo_two	*p;

	i = *((*((t_relay *)arg)).id) - 1;
	p = (t_philo_two *)((*((t_relay *)arg)).obj);
	while (p->arg.time_to_die * 1000L > timer_stop(p->philos[i].time_to_live)
		&& p->stop == 0 && p->philo_least_eat != p->arg.philo_num)
		usleep(10);
	sem_wait(p->sema.stop_mutex);
	if (p->stop == 0)
	{
		if (p->philo_least_eat == p->arg.philo_num)
			ft_printer(PHILO_ATE_ALL, i + 1, p->philos[i].gen_timer);
		else
			ft_printer(PHILO_DIE, i + 1, p->philos[i].gen_timer);
	}
	p->stop = 1;
	sem_post(p->sema.stop_mutex);
	ft_unblocking(p->sema.forks, p->arg.philo_num);
	return (NULL);
}
