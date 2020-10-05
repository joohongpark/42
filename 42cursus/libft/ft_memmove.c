/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:32:42 by joopark           #+#    #+#             */
/*   Updated: 2020/10/05 21:33:19 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	long			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;

	if (d == s || len == 0)
	{
		return (dst);
	}
	else if (d > s && (d - s) < (long)len)
	{
		i = (long)len - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
		return (dst);
	}
	else if (d < s && (s - d) < (long)len)
	{
		i = 0;
		while (i < (long)len)
		{
			d[i] = s[i];
			i++;
		}
		return (dst);
	}
	else
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
}
