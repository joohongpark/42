/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:35:10 by joopark           #+#    #+#             */
/*   Updated: 2020/08/11 17:35:12 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*rtn;

	i = 0;
	if (max <= min)
	{
		*range = (void *)0;
		return (0);
	}
	if (!(rtn = (int *)malloc(sizeof(int) * (max - min))))
		return (-1);
	while ((min + i) < max)
	{
		rtn[i] = min + i;
		i++;
	}
	*range = rtn;
	return (max - min);
}
