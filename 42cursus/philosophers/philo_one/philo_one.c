/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:41:07 by joopark           #+#    #+#             */
/*   Updated: 2021/04/13 23:31:01 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_one.h>
#include <stdio.h>

int ft_philo_init(t_philo_one *arg)
{
	int	i;

	i = 0;
	arg->philos = (t_philo *)malloc(sizeof(t_philo) * arg->arg.philo_num);
	if (arg->philos == NULL)
		return (-1);
	while (i < arg->arg.philo_num)
	{
		arg->philos[i].philo_id = i + 1;
		arg->philos[i].fork = 1;
		arg->philos[i].status = 0;
		i++;
	}
	return (0);
}

int ft_philo_gen(t_philo_one *arg)
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
	t_philo_one	philo_struct;
	//pthread_mutex_init(&mutex_fork, NULL);
	if (ft_arg_parser(argc, argv, &philo_struct.arg) == -1)
		return (-1);
	if (ft_philo_init(&philo_struct) == -1)
		return (-1);
	ft_philo_gen(&philo_struct);
	free(philo_struct.philos);
	return (0);
}
