/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 22:02:04 by joopark           #+#    #+#             */
/*   Updated: 2021/03/26 20:51:15 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

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
