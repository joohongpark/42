/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philospher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:55:39 by joopark           #+#    #+#             */
/*   Updated: 2021/04/14 01:28:00 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_one.h>

void			*ft_philosopher(void *arg)
{
	int			i;
	t_philo_one	*p;

	i = *((*((t_relay *)arg)).id) - 1;
	p = (t_philo_one *)((*((t_relay *)arg)).obj);
	p->philos[i].gen_timer = timer_start();
	p->philos[i].fsm_timer_t = timer_start();
	p->philos[i].time_to_live_t = timer_start();
	while (1)
	{
		p->philos[i].time_to_live = timer_stop(p->philos[i].time_to_live_t);
		if (p->philos[i].time_to_live > p->arg.time_to_die * 1000)
			break ;
		if (p->philos[i].status == 0)
		{
			if (ft_philo_get_fork(i + 1, p) == 1)
			{
				ft_printer(1, i + 1, p->philos[i].gen_timer);
				p->philos[i].fsm_timer_t = timer_start();
				p->philos[i].status = 1;
			}
		}
		else if (p->philos[i].status == 1)
		{
			ft_printer(2, i + 1, p->philos[i].gen_timer);
			p->philos[i].time_to_live_t = timer_start();
			p->philos[i].status = 2;
		}
		else if (p->philos[i].status == 2)
		{
			p->philos[i].fsm_timer = timer_stop(p->philos[i].fsm_timer_t);
			if (p->philos[i].fsm_timer > p->arg.time_to_eat * 1000)
			{
				p->philos[i].fsm_timer_t = timer_start();
				if (ft_philo_giveback_fork(i + 1, p) != 1)
					printf("error\n");
				ft_printer(3, i + 1, p->philos[i].gen_timer);
				p->philos[i].status = 3;
			}
		}
		else if (p->philos[i].status == 3)
		{
			p->philos[i].fsm_timer = timer_stop(p->philos[i].fsm_timer_t);
			if (p->philos[i].fsm_timer > p->arg.time_to_sleep * 1000)
			{
				ft_printer(0, i + 1, p->philos[i].gen_timer);
				p->philos[i].status = 0;
			}
		}
		usleep(10);
	}
	ft_printer(4, i + 1, p->philos[i].gen_timer);
	
	return (NULL);
}

int		ft_philo_get_fork(int right, t_philo_one *p)
{
	int left;
	int	left_fork;
	int	right_fork;

	if (right == 1)
		left = p->arg.philo_num;
	else
		left = right - 1;
	//pthread_mutex_lock(&mutex_fork);
	left_fork = p->philos[left - 1].fork;
	right_fork = p->philos[right - 1].fork;
	if (left_fork == 1 && right_fork == 1)
	{
		p->philos[left - 1].fork = 0;
		p->philos[right - 1].fork = 0;
	}
	//pthread_mutex_unlock(&mutex_fork);
	if (left_fork == 1 && right_fork == 1)
		return (1);
	else
		return (0);
}

int		ft_philo_giveback_fork(int right, t_philo_one *p)
{
	int left;
	int	left_fork;
	int	right_fork;

	if (right == 1)
		left = p->arg.philo_num;
	else
		left = right - 1;
	//pthread_mutex_lock(&mutex_fork);
	left_fork = p->philos[left - 1].fork;
	right_fork = p->philos[right - 1].fork;
	if (left_fork == 0 && right_fork == 0)
	{
		p->philos[left - 1].fork = 1;
		p->philos[right - 1].fork = 1;
	}
	//pthread_mutex_unlock(&mutex_fork);
	if (left_fork == 0 && right_fork == 0)
		return (1);
	else
		return (0);
}
