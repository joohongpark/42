/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 21:18:35 by joopark           #+#    #+#             */
/*   Updated: 2021/04/17 16:04:53 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_one.h>

void		ft_printer(int status, int philo_id, struct timeval time)
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