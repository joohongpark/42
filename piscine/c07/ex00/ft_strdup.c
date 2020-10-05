/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 11:14:18 by joopark           #+#    #+#             */
/*   Updated: 2020/08/11 11:18:35 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_strdup(char *src)
{
	int			idx;
	char		*rtn;

	idx = 0;
	while (src[idx] != '\0')
		idx++;
	if (!(rtn = malloc(sizeof(char) * (idx + 1))))
		return ((char *)0);
	while (idx >= 0)
	{
		rtn[idx] = src[idx];
		idx--;
	}
	return (rtn);
}
