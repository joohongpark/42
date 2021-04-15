/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philospher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:55:39 by joopark           #+#    #+#             */
/*   Updated: 2021/04/16 02:38:18 by joopark          ###   ########.fr       */
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
	while (p->philo_all_live > 0)
	{
		p->philos[i].time_to_live = timer_stop(p->philos[i].time_to_live_t);
		if (p->philos[i].time_to_live > p->arg.time_to_die * 1000)
		{
			// printer 함수에 mutex 걸고 p->philo_all_live 값 이용해 출력해도 되는지 확인하게해야함.
			pthread_mutex_lock(&(p->mutex_stop));
			if (p->philo_all_live == 1)
				p->philo_all_live = 0;
			if (p->philo_all_live == 0)
			{
				ft_printer(4, i + 1, p->philos[i].gen_timer);
				for (int i = 0; i < p->arg.philo_num; i++)
				{
					printf("fork %d : %d\n", i, p->philos[i].fork);
				}
				p->philo_all_live = p->philo_all_live - 1;
			}
			pthread_mutex_unlock(&(p->mutex_stop));
			break ;
		}
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
		usleep(100);
	}
	return (NULL);
}

int		ft_philo_get_fork(int right, t_philo_one *p)
{
	int left;
	int i;

	if (right == 1)
		left = p->arg.philo_num;
	else
		left = right - 1;
	i = right - 1;
	if (right % 2 == 0) // even
	{
		if (p->philos[i].fork_got == 0)
		{
			pthread_mutex_lock(&(p->philos[right - 1].fork_mutex));
			if (p->philos[right - 1].fork == 1) {
				p->philos[right - 1].fork = 0;
				p->philos[i].fork_got++;
			}
			pthread_mutex_unlock(&(p->philos[right - 1].fork_mutex));
		}
		if (p->philos[i].fork_got == 1)
		{
			pthread_mutex_lock(&(p->philos[left - 1].fork_mutex));
			if (p->philos[left - 1].fork == 1) {
				p->philos[left - 1].fork = 0;
				p->philos[i].fork_got++;
			}
			pthread_mutex_unlock(&(p->philos[left - 1].fork_mutex));
		}
	}
	else // odd
	{
		if (p->philos[i].fork_got == 0)
		{
			pthread_mutex_lock(&(p->philos[left - 1].fork_mutex));
			if (p->philos[left - 1].fork == 1) {
				p->philos[left - 1].fork = 0;
				p->philos[i].fork_got++;
			}
			pthread_mutex_unlock(&(p->philos[left - 1].fork_mutex));
		}
		if (p->philos[i].fork_got == 1)
		{
			pthread_mutex_lock(&(p->philos[right - 1].fork_mutex));
			if (p->philos[right - 1].fork == 1) {
				p->philos[right - 1].fork = 0;
				p->philos[i].fork_got++;
			}
			pthread_mutex_unlock(&(p->philos[right - 1].fork_mutex));
		}
	}
	if (p->philos[i].fork_got == 2)
		return (1);
	else
		return (0);
}

int		ft_philo_giveback_fork(int right, t_philo_one *p)
{
	int left;

	if (right == 1)
		left = p->arg.philo_num;
	else
		left = right - 1;
	pthread_mutex_lock(&(p->philos[left - 1].fork_mutex));
	pthread_mutex_lock(&(p->philos[right - 1].fork_mutex));
	if (p->philos[right - 1].fork == 0)
		p->philos[right - 1].fork = 1;
	if (p->philos[left - 1].fork == 0)
		p->philos[left - 1].fork = 1;
	pthread_mutex_unlock(&(p->philos[right - 1].fork_mutex));
	pthread_mutex_unlock(&(p->philos[left - 1].fork_mutex));
	return (1);
}
