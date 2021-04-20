/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:23:24 by joopark           #+#    #+#             */
/*   Updated: 2021/04/18 16:44:42 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_two.h>

struct timeval	timer_start(void)
{
	struct timeval	rtn;

	gettimeofday(&rtn, NULL);
	return (rtn);
}

long	timer_stop(struct timeval time_start)
{
	long			us_start;
	long			us_stop;
	struct timeval	time_stop;

	gettimeofday(&time_stop, NULL);
	us_start = time_start.tv_sec * 1000000 + time_start.tv_usec;
	us_stop = time_stop.tv_sec * 1000000 + time_stop.tv_usec;
	return (us_stop - us_start);
}
