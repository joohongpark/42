/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:48:22 by joopark           #+#    #+#             */
/*   Updated: 2020/10/19 19:48:23 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void		*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

size_t		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

char		*ft_strnstr(char *haystack, char *needle, size_t len)
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
