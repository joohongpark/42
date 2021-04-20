/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:41:07 by joopark           #+#    #+#             */
/*   Updated: 2021/04/20 12:56:17 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_two.h>

sem_t	*ft_sem_gen(char *name, int value)
{
	sem_t	*rtn;

	sem_unlink(name);
	rtn = sem_open(name, O_CREAT | O_EXCL, S_IRWXU, value);
	return (rtn);
}

int	ft_philo_init(t_philo_two *arg)
{
	int	i;

	i = 0;
	arg->philos = (t_philo *)malloc(sizeof(t_philo) * arg->arg.philo_num);
	if (arg->philos == NULL)
		return (-1);
	arg->sema.forks = ft_sem_gen("philo_two_fork", arg->arg.philo_num);
	arg->sema.eat_cnt_mutex = ft_sem_gen("philo_two_eat_cnt", 1);
	arg->sema.stop_mutex = ft_sem_gen("philo_two_stop", 1);
	arg->philo_least_eat = 0;
	arg->stop = 0;
	while (i < arg->arg.philo_num)
	{
		arg->philos[i].philo_id = i + 1;
		if (arg->arg.number_of_times_each_philo_must_eat != -1)
			arg->philos[i].eat_cnt = 0;
		else
			arg->philos[i].eat_cnt = -1;
		i++;
	}
	return (0);
}

int	ft_philo_gen(t_philo_two *arg)
{
	int			i;
	pthread_t	*thread;
	t_relay		*data;

	i = 0;
	data = (t_relay *)malloc(sizeof(t_relay) * arg->arg.philo_num);
	if (data == NULL)
		return (-1);
	while (i < arg->arg.philo_num)
	{
		thread = &(arg->philos[i].thread);
		data[i].id = &arg->philos[i].philo_id;
		data[i].obj = (void *)arg;
		pthread_create(thread, NULL, ft_philosopher, (void *)&data[i]);
		usleep(50);
		i++;
	}
	i = 0;
	while (i < arg->arg.philo_num)
	{
		pthread_join(arg->philos[i].thread, NULL);
		i++;
	}
	free(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_philo_two	philo_struct;

	if (ft_arg_parser(argc, argv, &philo_struct.arg) == -1)
		return (-1);
	if (ft_philo_init(&philo_struct) == -1)
		return (-1);
	ft_philo_gen(&philo_struct);
	free(philo_struct.philos);
	return (0);
}
