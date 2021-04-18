/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:46:15 by joopark           #+#    #+#             */
/*   Updated: 2021/04/18 13:44:49 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_one.h>

void		ft_set_fork_seq(int *first, int *second, int i, int len)
{
	int left;
	int right;

	right = i;
	if (right == 0)
		left = len - 1;
	else
		left = right - 1;
	if (right % 2 == 0)
	{
		*first = left;
		*second = right;
	}
	else
	{
		*first = right;
		*second = left;
	}
}

int			ft_get_fork_atomic(int *fork, pthread_mutex_t *mutex)
{
	int		rtn;

	rtn = 0;
	pthread_mutex_lock(mutex);
	if (*fork == 1) {
		*fork = 0;
		rtn = 1;
	}
	pthread_mutex_unlock(mutex);
	return (rtn);
}

int			ft_giveback_fork_atomic(int *fork, pthread_mutex_t *mutex)
{
	int		rtn;

	rtn = 0;
	pthread_mutex_lock(mutex);
	if (*fork == 0) {
		*fork = 1;
		rtn = 1;
	}
	pthread_mutex_unlock(mutex);
	return (rtn);
}
