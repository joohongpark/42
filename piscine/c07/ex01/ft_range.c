/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:14:58 by joopark           #+#    #+#             */
/*   Updated: 2020/08/11 12:15:29 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			*ft_range(int min, int max)
{
	int		i;
	int		*rtn;

	i = 0;
	if (max <= min)
		return ((void *)0);
	if (!(rtn = (int *)malloc(sizeof(int) * (max - min))))
		return ((void *)0);
	while ((min + i) < max)
	{
		rtn[i] = min + i;
		i++;
	}
	return (rtn);
}
