/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watchdog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:24:54 by joopark           #+#    #+#             */
/*   Updated: 2021/04/22 23:08:18 by joopark          ###   ########.fr       */
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
	int				i;
	unsigned long	ttd;
	t_philo_two		*p;

	i = *((*((t_relay *)arg)).id) - 1;
	p = (t_philo_two *)((*((t_relay *)arg)).obj);
	while (1)
	{
		sem_wait(p->philos[i].cnt_mutex);
		ttd = timer_stop(p->philos[i].time_to_live);
		sem_post(p->philos[i].cnt_mutex);
		if ((p->arg.time_to_die * 1000UL) < ttd
			|| p->stop != 0 || p->philo_least_eat == p->arg.philo_num)
			break ;
		usleep(100);
	}
	sem_wait(p->sema.stop_mutex);
	if ((p->stop == 0) && (p->philo_least_eat == p->arg.philo_num))
		ft_printer(PHILO_ATE_ALL, i + 1, p->philos[i].gen_timer);
	else if ((p->stop == 0) && (p->philo_least_eat != p->arg.philo_num))
		ft_printer(PHILO_DIE, i + 1, p->philos[i].gen_timer);
	p->stop = 1;
	sem_post(p->sema.stop_mutex);
	ft_unblocking(p->sema.forks, p->arg.philo_num);
	return (NULL);
}
