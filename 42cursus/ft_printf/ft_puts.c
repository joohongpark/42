/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:24:13 by joopark           #+#    #+#             */
/*   Updated: 2020/10/29 20:48:33 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_putnbr_base(size_t nbr, char *base)
{
	char			c;
	int				digit;
	size_t			basecnt;

	digit = ft_strlen(base);
	if (digit < 2)
		return ;
	ft_intlen(nbr, digit, &basecnt);
	while (basecnt)
	{
		c = base[(int)(nbr / basecnt)];
		write(1, &c, 1);
		nbr = nbr % basecnt;
		basecnt /= digit;
	}
}

int					ft_putstr(char *str, int lim)
{
	return (write(1, str, lim));
}

int					ft_putchar(char c, int len)
{
	int				i;

	i = 0;
	while (i < len)
		i += write(1, &c, 1);
	return (i);
}