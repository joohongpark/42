/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watchdog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:24:54 by joopark           #+#    #+#             */
/*   Updated: 2021/04/21 21:29:44 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_three.h>

void	*ft_watchdog(void *arg)
{
	int	i;
	t_philo_three *p;

	p = (t_philo_three *)arg;
	i = p->philo.philo_id - 1;
	while (p->arg.time_to_die * 1000L > timer_stop(p->philo.time_to_live))
		usleep(10);
	p->stop = 1;
	return (NULL);
}

void	*ft_watchdog_die(void *arg)
{
	t_philo_three	*p;
	int				i;
	int				rtnval;
	pid_t			pid;

	p = (t_philo_three *)arg;
	i = 0;
	while (p->die_id == 0)
	{
		pid = waitpid(p->pids[i], &rtnval, WNOHANG);
		if (i == (p->arg.philo_num - 1))
			i = 0;
		else
			i++;
		if (pid != 0)
			break ;
		usleep(1);
	}
	p->die_id = i + 1;
	sem_post(p->sema.main_watchdog);
	return (NULL);
}

void	*ft_watchdog_eat(void *arg)
{
	t_philo_three	*p;
	int				i;

	p = (t_philo_three *)arg;
	i = 0;
	while (i < p->arg.philo_num)
	{
		sem_wait(p->sema.eat_cnt);
		i++;
	}
	sem_post(p->sema.main_watchdog);
	return (NULL);
}
