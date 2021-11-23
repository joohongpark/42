/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:23:14 by joopark           #+#    #+#             */
/*   Updated: 2021/11/23 14:00:42 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	tmp;
	long	base;
	char	c;

	if (n >= 0)
		tmp = (long)n;
	else
		tmp = -1L * n;
	base = 1L;
	while ((base * 10L) <= tmp)
		base *= 10;
	if (n < 0)
		write(fd, "-", 1);
	while (base > 0)
	{
		c = (tmp / base) + '0';
		write(fd, &c, 1);
		tmp = tmp % base;
		base /= 10;
	}
}

long	ft_strlen(char *str)
{
	long	i;

	i = 0;
	while (str[i])
	{
		i++;
	}	
	return (i);
}

int	ft_atoi(const char *str)
{
	long	sum;

	sum = 0;
	while ((*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\f')
		|| (*str == '\r') || (*str == ' '))
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = (long)(*str++ - '0') + sum * 10L;
		if (sum > 2147483647L)
		{
			return (-1);
		}
		if (sum < -2147483648L)
		{
			return (0);
		}
	}
	return ((int)sum);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
	{
		write(fd, s, ft_strlen(s));
	}
}
