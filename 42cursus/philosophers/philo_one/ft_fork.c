/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:46:15 by joopark           #+#    #+#             */
/*   Updated: 2021/04/18 16:02:26 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_one.h>

void	ft_set_fork_seq(int *first, int *second, int i, int len)
{
	int	left;
	int	right;

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

int	ft_get_fork(int i, t_philo *philo)
{
	int		rtn;

	rtn = 0;
	pthread_mutex_lock(&philo[i].fork_mutex);
	if (philo[i].fork == 1)
	{
		philo[i].fork = 0;
		rtn = 1;
	}
	pthread_mutex_unlock(&philo[i].fork_mutex);
	return (rtn);
}

void	ft_giveback_fork_atomic(int i, int j, t_philo *philo)
{
	pthread_mutex_lock(&philo[i].fork_mutex);
	pthread_mutex_lock(&philo[j].fork_mutex);
	philo[i].fork = 1;
	philo[j].fork = 1;
	pthread_mutex_unlock(&philo[j].fork_mutex);
	pthread_mutex_unlock(&philo[i].fork_mutex);
}
