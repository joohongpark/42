/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 05:03:27 by joopark           #+#    #+#             */
/*   Updated: 2020/10/08 14:25:59 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*rtn;
	int		tmp;
	int		len;

	tmp = n >= 0 ? n : -1 * n;
	len = n >= 0 ? 1 : 2;
	while (len++)
	{
		tmp /= 10;
		if (tmp == 0)
			break;
	}
	if (!(rtn = (char *)malloc(sizeof(char) * len)))
		return (NULL);
}
