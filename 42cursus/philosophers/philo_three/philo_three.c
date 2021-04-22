/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:41:07 by joopark           #+#    #+#             */
/*   Updated: 2021/04/23 00:18:25 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_three.h>

sem_t	*ft_sem_gen(char *name, int value)
{
	sem_t	*rtn;

	sem_unlink(name);
	rtn = sem_open(name, O_CREAT | O_EXCL, S_IRWXU, value);
	return (rtn);
}

int	ft_philo_init(t_philo_three *arg)
{
	int	i;

	i = 0;
	arg->sema.forks = ft_sem_gen("philo_three_fork", arg->arg.philo_num);
	arg->sema.eat_cnt = ft_sem_gen("philo_three_eat_cnt", 0);
	arg->sema.stop_mutex = ft_sem_gen("philo_three_stop", 0);
	arg->sema.print_mutex = ft_sem_gen("philo_three_print", 1);
	arg->sema.main_watchdog = ft_sem_gen("philo_three_watchdog", 0);
	arg->philo.gen_timer = timer_start();
	arg->stop = 0;
	arg->die_id = 0;
	if (arg->arg.number_of_times_each_philo_must_eat != -1)
		arg->philo.eat_cnt = 0;
	else
		arg->philo.eat_cnt = -1;
	return (0);
}

void	ft_philo_watchdog(t_philo_three *arg)
{
	int			i;
	pthread_t	watchdog_die;
	pthread_t	watchdog_eat;

	i = 0;
	pthread_create(&watchdog_die, NULL, ft_watchdog_die, (void *)arg);
	pthread_create(&watchdog_eat, NULL, ft_watchdog_eat, (void *)arg);
	sem_wait(arg->sema.main_watchdog);
	if (arg->die_id == 0)
		ft_printer(PHILO_ATE_ALL, arg->die_id, arg->philo.gen_timer);
	else
		ft_printer(PHILO_DIE, arg->die_id, arg->philo.gen_timer);
	ft_unblocking(arg->sema.eat_cnt, arg->arg.philo_num);
	arg->die_id = 1;
	pthread_join(watchdog_die, NULL);
	pthread_join(watchdog_eat, NULL);
	i = 0;
	while (i < arg->arg.philo_num)
	{
		kill(arg->pids[i], SIGKILL);
		i++;
	}
	free(arg->pids);
}

int	ft_philo_gen(t_philo_three *arg)
{
	int			i;
	pid_t		pid;

	i = 0;
	arg->pids = (pid_t *)malloc(sizeof(pid_t) * arg->arg.philo_num);
	while (i < arg->arg.philo_num)
	{
		pid = fork();
		if (pid <= 0)
			free(arg->pids);
		if (pid == -1)
			return (-1);
		if (pid <= 0)
		{
			ft_philosopher(arg, i);
			return (1);
		}
		arg->pids[i] = pid;
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_philo_three	philo_struct;

	if (ft_arg_parser(argc, argv, &philo_struct.arg) == -1)
		return (-1);
	if (ft_philo_init(&philo_struct) == -1)
		return (-1);
	if (ft_philo_gen(&philo_struct) == 0)
		ft_philo_watchdog(&philo_struct);
	return (0);
}
