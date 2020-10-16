/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:11:06 by joopark           #+#    #+#             */
/*   Updated: 2020/10/15 22:37:31 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*rtn;
	size_t	cnt;
	size_t	s1len;
	size_t	s2len;

	if (s1 == ((char *)0) || s2 == ((char *)0))
		return (((char *)0));
	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	cnt = 0;
	if (!(rtn = (char *)malloc(sizeof(char) * (s1len + s2len + 1))))
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

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	s_p;
	size_t	f_p;

	s_p = 0;
	f_p = 0;
	while (haystack[s_p] != '\0' && len > 0)
	{
		if (haystack[s_p] == needle[f_p])
			f_p++;
		else
		{
			if (needle[f_p] == '\0')
				return ((char *)&haystack[s_p - f_p]);
			else
				f_p = (haystack[s_p] == needle[0]) ? 1 : 0;
		}
		s_p++;
		len--;
	}
	return ((needle[f_p] == '\0') ? ((char *)&haystack[s_p - f_p]) : (void*)0);
}

size_t		ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (dst == ((char *)0) || src == ((char *)0))
		return (0);
	len = ft_strlen((char *)src);
	while ((dstsize > i + 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (len);
}
