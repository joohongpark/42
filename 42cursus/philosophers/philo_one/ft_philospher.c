/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philospher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:55:39 by joopark           #+#    #+#             */
/*   Updated: 2021/04/17 01:09:07 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_one.h>

void			*ft_philosopher(void *arg)
{
	int			i;
	int			status;
	int			first;
	int			second;
	t_philo_one	*p;

	i = *((*((t_relay *)arg)).id) - 1;
	p = (t_philo_one *)((*((t_relay *)arg)).obj);
	status = 0;
	p->philos[i].gen_timer = timer_start();
	p->philos[i].fsm_timer_t = timer_start();
	p->philos[i].time_to_live_t = timer_start();
	ft_set_fork_seq(&first, &second, i, p->arg.philo_num);
	printf("philo %d : (%d, %d)\n", i + 1, first, second);
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
				p->philo_all_live = p->philo_all_live - 1;
			}
			pthread_mutex_unlock(&(p->mutex_stop));
			break ;
		}
		if (status == 0)
		{
			if (ft_get_fork_atomic(&p->philos[first].fork, &(p->philos[first].fork_mutex)) == 1)
				status = 1;
		}
		else if (status == 1)
		{
			if (ft_get_fork_atomic(&p->philos[second].fork, &(p->philos[second].fork_mutex)) == 1)
			{
				ft_printer(1, i + 1, p->philos[i].gen_timer);
				p->philos[i].fsm_timer_t = timer_start();
				status = 2;
			}
			else
			{
				ft_giveback_fork_atomic(&p->philos[first].fork, &(p->philos[first].fork_mutex));
				status = 0;
			}
		}
		else if (status == 2)
		{
			ft_printer(2, i + 1, p->philos[i].gen_timer);
			p->philos[i].time_to_live_t = timer_start();
			status = 3;
		}
		else if (status == 3)
		{
			p->philos[i].fsm_timer = timer_stop(p->philos[i].fsm_timer_t);
			if (p->philos[i].fsm_timer > p->arg.time_to_eat * 1000)
			{
				p->philos[i].fsm_timer_t = timer_start();
				if (ft_giveback_fork_atomic(&p->philos[first].fork, &(p->philos[first].fork_mutex)) != 1
					|| ft_giveback_fork_atomic(&p->philos[second].fork, &(p->philos[second].fork_mutex)) != 1)
					printf("error\n");
				ft_printer(3, i + 1, p->philos[i].gen_timer);
				status = 4;
			}
		}
		else if (status == 4)
		{
			p->philos[i].fsm_timer = timer_stop(p->philos[i].fsm_timer_t);
			if (p->philos[i].fsm_timer > p->arg.time_to_sleep * 1000)
			{
				ft_printer(0, i + 1, p->philos[i].gen_timer);
				status = 0;
			}
		}
		usleep(1);
	}
	return (NULL);
}
