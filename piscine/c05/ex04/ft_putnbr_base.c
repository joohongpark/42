/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 12:05:00 by joopark           #+#    #+#             */
/*   Updated: 2020/08/09 17:46:47 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int					basedigit(char *base)
{
	int				i;
	char			tmp[256];

	i = 0;
	while (i < 256)
		tmp[i++] = 0;
	i = 0;
	while (base[i] != '\0')
	{
		if (tmp[(unsigned char)base[i]] == 0)
			tmp[(unsigned char)base[i]] = 1;
		else
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (i);
}

void				ft_putnbr_base(int nbr, char *base)
{
	char			c;
	int				digit;
	long			basecnt;
	long			tmp;

	digit = basedigit(base);
	if (digit < 2)
		return ;
	tmp = (nbr < 0) ? nbr * -1L : nbr * 1L;
	basecnt = 1;
	while ((basecnt * digit) <= tmp)
		basecnt *= digit;
	if (nbr < 0)
		write(1, "-", 1);
	while (basecnt > 0)
	{
		c = base[tmp / basecnt];
		write(1, &c, 1);
		tmp = tmp % basecnt;
		basecnt = basecnt / digit;
	}
}
