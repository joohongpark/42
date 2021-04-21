/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:53:43 by joopark           #+#    #+#             */
/*   Updated: 2021/04/20 13:07:12 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_three.h>

int	ft_arg_parser(int argc, char *argv[], t_arg *s)
{
	if ((argc != 5 && argc != 6)
		|| ft_atoi(argv[1], &(s->philo_num)) == -1
		|| ft_atoi(argv[2], &(s->time_to_die)) == -1
		|| ft_atoi(argv[3], &(s->time_to_eat)) == -1
		|| ft_atoi(argv[4], &(s->time_to_sleep)) == -1)
		return (-1);
	if (argc == 6
		&& ft_atoi(argv[5], &(s->number_of_times_each_philo_must_eat)) == -1)
		return (-1);
	if (s->philo_num <= 1
		|| s->time_to_die <= 0
		|| s->time_to_eat <= 0
		|| s->time_to_sleep <= 0
		|| (argc == 6 && s->number_of_times_each_philo_must_eat < 0))
		return (-1);
	if (argc == 5)
		s->number_of_times_each_philo_must_eat = -1;
	return (0);
}

int	ft_atoi(const char *str, int *value)
{
	long	sum;
	long	p;

	sum = 0;
	p = 1;
	while ((*str == '\t') || (*str == '\n') || (*str == '\r') || (*str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			p = p * -1L;
		str++;
	}
	if (*str == '\0')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		sum = (long)(*str++ - '0') + sum * 10L;
		if (sum * p > 2147483647L)
			return (-1);
		if (sum * p < -2147483648L)
			return (-1);
	}
	*value = (int)(sum * p);
	return (0);
}
