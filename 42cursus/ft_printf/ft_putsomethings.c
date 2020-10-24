/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsomethings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 01:36:14 by joopark           #+#    #+#             */
/*   Updated: 2020/10/24 12:23:55 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putnbr_fd(int n, int fd)
{
	long	tmp;
	long	base;
	char	c;
	int		rtn;

	tmp = n >= 0 ? (long)n : -1L * n;
	base = 1L;
	while ((base *= 10) < tmp)
		;
	rtn = (n < 0) ? 1 : 0;
	if (n < 0)
		write(fd, "-", 1);
	while (base /= 10)
	{
		c = (tmp / base) + '0';
		write(fd, &c, 1);
		tmp = tmp % base;
		rtn++;
	}
	return (rtn);
}
