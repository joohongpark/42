/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philospher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:55:39 by joopark           #+#    #+#             */
/*   Updated: 2021/04/18 00:31:20 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_one.h>

void			*ft_philosopher(void *arg)
{
	int			i;
	int			status;
	t_philo_one	*p;

	i = *((*((t_relay *)arg)).id) - 1;
	p = (t_philo_one *)((*((t_relay *)arg)).obj);
	status = PHILO_THINKING;
	p->philos[i].gen_timer = timer_start();
	p->philos[i].fsm_timer_t = p->philos[i].gen_timer;
	p->philos[i].time_to_live_t = p->philos[i].gen_timer;
	while (ft_watchdog(i, p) == 1)
	{
		status = ft_philo_fsm(status, i, p);
		ft_philo_fsm_do(status, i, p);
		pthread_mutex_lock(&(p->print_mutex));
		if (p->print == 1)
			ft_printer(status, i + 1, p->philos[i].gen_timer);
		pthread_mutex_unlock(&(p->print_mutex));
		usleep(0);
	}
	pthread_mutex_lock(&(p->print_mutex));
	if (p->print == 1)
	{
		if (p->philo_least_eat == p->arg.philo_num)
			ft_printer(PHILO_ATE_ALL, i + 1, p->philos[i].gen_timer);
		else
			ft_printer(PHILO_DIE, i + 1, p->philos[i].gen_timer);
		p->print = 0;
	}
	pthread_mutex_unlock(&(p->print_mutex));
	return (NULL);
}

int			ft_philo_fsm(int status, int i, t_philo_one *p)
{
	int			first;
	int			second;

	ft_set_fork_seq(&first, &second, i, p->arg.philo_num);
	if (status == PHILO_THINKING)
		return (PHILO_THINKING + 1);
	else if ( (status == (PHILO_THINKING + 1))
		&& (ft_get_fork_atomic(&p->philos[first].fork, &(p->philos[first].fork_mutex)) == 1))
		return (PHILO_THINKING + 2);
	else if ( (status == (PHILO_THINKING + 2))
		&& (ft_get_fork_atomic(&p->philos[second].fork, &(p->philos[second].fork_mutex)) == 1))
		return (PHILO_GET_FORK);
	else if (status == PHILO_GET_FORK)
		return (PHILO_EATING);
	else if (status == PHILO_EATING)
		return (PHILO_EATING + 1);
	else if ( (status == (PHILO_EATING + 1))
		&& (timer_stop(p->philos[i].fsm_timer_t) > p->arg.time_to_eat * 1000))
		return (PHILO_SLEEPING);
	else if (status == PHILO_SLEEPING)
		return (PHILO_SLEEPING + 1);
	else if ( (status == (PHILO_SLEEPING + 1))
		&& (timer_stop(p->philos[i].fsm_timer_t) > p->arg.time_to_sleep * 1000))
		return (PHILO_THINKING);
	return (status);
}

void			ft_philo_fsm_do(int status, int i, t_philo_one *p)
{
	int			first;
	int			second;

	ft_set_fork_seq(&first, &second, i, p->arg.philo_num);
	if (status == PHILO_EATING)
	{
		p->philos[i].time_to_live_t = timer_start();
		p->philos[i].fsm_timer_t = timer_start();
	}
	else if (status == PHILO_SLEEPING)
	{
		if (p->arg.number_of_times_each_philo_must_eat != -1)
			p->philos[i].eat_cnt = p->philos[i].eat_cnt + 1;
		if (p->philos[i].eat_cnt == p->arg.number_of_times_each_philo_must_eat)
		{
			pthread_mutex_lock(&(p->philo_least_eat_mutex));
			if (p->stop == 1)
				p->philo_least_eat = p->philo_least_eat + 1;
			pthread_mutex_unlock(&(p->philo_least_eat_mutex));
		}
		p->philos[i].fsm_timer_t = timer_start();
		if (ft_giveback_fork_atomic(&p->philos[first].fork, &(p->philos[first].fork_mutex)) != 1
			|| ft_giveback_fork_atomic(&p->philos[second].fork, &(p->philos[second].fork_mutex)) != 1)
			printf("error\n");
	}
}
