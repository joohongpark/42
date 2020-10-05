/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 09:56:06 by joopark           #+#    #+#             */
/*   Updated: 2020/08/13 09:56:08 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		if ((base[i] == '\t')
			|| (base[i] == '\n')
			|| (base[i] == '\v')
			|| (base[i] == '\f')
			|| (base[i] == '\r')
			|| (base[i] == ' ')
			|| (base[i] == '+')
			|| (base[i] == '-'))
			return (0);
		i++;
	}
	return (i);
}

long				baseget(int digit, long num, int *size)
{
	long			basecnt;

	*size = 0;
	basecnt = 1;
	while ((basecnt * digit) <= num)
	{
		basecnt *= digit;
		*size = *size + 1;
	}
	return (basecnt);
}

char				*ft_putnbr_base(int nbr, char *base)
{
	char			*rtn;
	int				digit;
	int				size;
	long			basecnt;
	long			tmp;

	digit = basedigit(base);
	if (digit < 2)
		return ((char *)0);
	tmp = (nbr < 0) ? nbr * -1L : nbr * 1L;
	basecnt = baseget(digit, tmp, &size);
	size = (nbr < 0) ? (size + 1) : (size + 2);
	if (!(rtn = (char *)malloc(sizeof(char) * size)))
		return ((char *)0);
	size = 0;
	if (nbr < 0)
		rtn[size++] = '-';
	while (basecnt > 0)
	{
		rtn[size++] = base[tmp / basecnt];
		tmp = tmp % basecnt;
		basecnt = basecnt / digit;
	}
	rtn[size++] = '\0';
	return (rtn);
}
