/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 21:18:35 by joopark           #+#    #+#             */
/*   Updated: 2021/04/13 21:26:41 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_one.h>

void		ft_printer(int status, int philo_id, struct timeval time)
{
	long	ms;
	char	*msg;

	ms = timer_stop(time) / 1000;
	if (status == 0)
		msg = "is thinking";
	else if (status == 1)
		msg = "has taken a fork";
	else if (status == 2)
		msg = "is eating";
	else if (status == 3)
		msg = "is sleeping";
	else
		msg = "died";
	printf("[%ld ms] philosopher %d %s\n", ms, philo_id, msg);
}