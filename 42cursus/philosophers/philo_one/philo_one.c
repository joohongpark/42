/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:41:07 by joopark           #+#    #+#             */
/*   Updated: 2021/04/12 01:49:34 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_one.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_arg	arg;

	printf("argc : %d\n", argc);
	if (ft_arg_parser(argc, argv, &arg) == -1)
		return (-1);
	printf("number_of_philosophers : %d\n", arg.number_of_philo);
	printf("time_to_die : %d\n", arg.time_to_die);
	printf("time_to_eat : %d\n", arg.time_to_eat);
	printf("time_to_sleep  : %d\n", arg.time_to_sleep );
	printf("number_of_times_each_philosopher_must_eat : %d\n", arg.number_of_times_each_philo_must_eat);



	return (0);
}
