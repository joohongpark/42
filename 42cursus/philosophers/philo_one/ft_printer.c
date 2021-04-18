/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 21:18:35 by joopark           #+#    #+#             */
/*   Updated: 2021/04/18 15:52:41 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_one.h>

void	ft_printer(int status, int philo_id, struct timeval time)
{
	long	ms;
	char	*msg;

	ms = timer_stop(time) / 1000;
	msg = NULL;
	if (status == PHILO_THINKING)
		msg = "is thinking";
	else if (status == PHILO_GET_FORK)
		msg = "has taken a fork";
	else if (status == PHILO_EATING)
		msg = "is eating";
	else if (status == PHILO_SLEEPING)
		msg = "is sleeping";
	else if (status == PHILO_DIE)
		msg = "died";
	else if (status == PHILO_ATE_ALL)
		msg = "All philosophers ate enough pasta! :D";
	if (msg != NULL)
	{
		if (status != PHILO_ATE_ALL)
			printf("[%ld ms] philosopher %d %s\n", ms, philo_id, msg);
		else
			printf("[%ld ms] %s\n", ms, msg);
	}
}

void	ft_printer_mutex(int status, int philo_id, t_philo_one *p)
{
	struct timeval	time;

	pthread_mutex_lock(&(p->print_mutex));
	if (p->print == 1)
	{
		time = p->philos[philo_id - 1].gen_timer;
		if (status == -1)
		{
			if (p->philo_least_eat == p->arg.philo_num)
				ft_printer(PHILO_ATE_ALL, philo_id, time);
			else
				ft_printer(PHILO_DIE, philo_id, time);
			p->print = 0;
		}
		else
		{
			ft_printer(status, philo_id, time);
		}
	}
	pthread_mutex_unlock(&(p->print_mutex));
}
