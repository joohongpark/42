/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:21:07 by joopark           #+#    #+#             */
/*   Updated: 2020/08/17 15:21:09 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				*ft_map(int *tab, int length, int (*f)(int))
{
	int			i;
	int			*rtn;

	i = 0;
	if (!(rtn = malloc(sizeof(int) * length)))
		return ((int *)0);
	while (i < length)
	{
		rtn[i] = (f)(tab[i]);
		i++;
	}
	return (rtn);
}
