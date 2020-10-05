/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 08:11:02 by joopark           #+#    #+#             */
/*   Updated: 2020/10/05 17:56:55 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	size_t	cnt;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	cnt = 0;
	if (!(rtn = (char *)malloc(sizeof(char) * (s1len + s2len))))
		return ((char *)0);
	while (cnt < s1len)
	{
		rtn[cnt] = s1[cnt];
		cnt++;
	}
	while (cnt < (s1len + s2len))
	{
		rtn[cnt] = s2[cnt - s1len];
		cnt++;
	}
	rtn[cnt] = '\0';
	return (rtn);
}
