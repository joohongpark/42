/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:25:38 by joopark           #+#    #+#             */
/*   Updated: 2020/10/25 17:20:44 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	long	sum;
	long	p;

	sum = 0;
	p = 1;
	while ((*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\f')
		|| (*str == '\r') || (*str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		p = (*str == '-') ? (p * -1L) : p;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = (long)(*str++ - '0') + sum * 10L;
		if (sum * p > 2147483647L)
			return (-1);
		if (sum * p < -2147483648L)
			return (0);
	}
	return ((int)(sum * p));
}
