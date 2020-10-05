/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:23:37 by joopark           #+#    #+#             */
/*   Updated: 2020/08/09 10:23:39 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putnbr(int nb)
{
	long	nb_upcast;
	long	base;
	char	c;

	if (nb < 0)
		write(1, "-", 1);
	nb_upcast = (nb < 0) ? (nb * -1L) : (long)nb;
	base = 1;
	while ((base * 10L) < nb_upcast)
		base *= 10;
	while (base > 0)
	{
		c = (char)(nb_upcast / base) + '0';
		write(1, &c, 1);
		nb_upcast %= base;
		base /= 10;
	}
}
