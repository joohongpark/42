/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 07:48:28 by joopark           #+#    #+#             */
/*   Updated: 2020/10/05 17:09:52 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	cnt;

	cnt = 0;
	if (!(rtn = (char *)malloc(sizeof(char) * len)))
		return ((char *)0);
	while (cnt < len)
	{
		rtn[cnt] = s[cnt];
		cnt++;
	}
	rtn[cnt] = '\0';
	return (rtn);
}
