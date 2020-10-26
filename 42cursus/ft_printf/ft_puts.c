/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:24:13 by joopark           #+#    #+#             */
/*   Updated: 2020/10/26 16:24:14 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_putnbr_base(unsigned int nbr, char *base)
{
	char			c;
	int				digit;
	long			basecnt;
	long			tmp;
	int				rtn;

	rtn = 0;
	digit = ft_strlen(base);
	if (digit < 2)
		return (rtn);
	tmp = nbr * 1L;
	basecnt = 1;
	while ((basecnt *= digit) < tmp)
		rtn++;
	while (basecnt /= digit)
	{
		c = base[tmp / basecnt];
		write(1, &c, 1);
		tmp = tmp % basecnt;
	}
	return (rtn);
}

int					ft_putnbr_fd(int n, int fd)
{
	long			tmp;
	long			base;
	char			c;
	int				rtn;

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
