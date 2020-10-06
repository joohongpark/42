/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 22:02:04 by joopark           #+#    #+#             */
/*   Updated: 2020/10/06 22:02:05 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long 	sum;
	long 	p;

	sum = 0;
	p = 1;
	while ((*str == '\t')
		|| (*str == '\n')
		|| (*str == '\v')
		|| (*str == '\f')
		|| (*str == '\r')
		|| (*str == ' '))
		str++;
	while (*str == '+' || *str == '-')
		p = (*str++ == '-') ? (p * -1L) : p;
	while (*str >= '0' && *str <= '9')
	{
		sum = (long)(*str++ - '0') + sum * 10L;
		if (sum * p > 2147483647L)
			return (-1);
		if (sum * p < -2147483648L)
			return (0);
	}
	return ((int)sum * p);
}
