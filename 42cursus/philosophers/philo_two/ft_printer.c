/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 21:18:35 by joopark           #+#    #+#             */
/*   Updated: 2021/04/19 21:50:15 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_two.h>

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

void	ft_printer_mutex(int status, int philo_id, t_philo_two *p)
{
	struct timeval	time;

	sem_wait(p->sema.stop_mutex);
	if (p->stop == 0)
	{
		time = p->philos[philo_id - 1].gen_timer;
		ft_printer(status, philo_id, time);
	}
	sem_post(p->sema.stop_mutex);
}
