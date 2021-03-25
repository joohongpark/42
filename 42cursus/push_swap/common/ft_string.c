/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:03:15 by joopark           #+#    #+#             */
/*   Updated: 2021/03/26 01:21:01 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (dst == NULL || src == NULL)
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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
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
			f_p = 0;
			if (haystack[s_p] == needle[0])
				f_p = 1;
		}
		s_p++;
		len--;
	}
	if (needle[f_p] == '\0')
		return ((char *)&haystack[s_p - f_p]);
	return (NULL);
}

int	ft_str_is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (('0' <= str[i] && '9' >= str[i]))
			i++;
		else
			return (-1);
	}
	return (0);
}

char	*ft_strreplace(char *str, char *a, char *b)
{
	char	*rtn;
	char	*pos;
	char	*pos_next;

	pos = str;
	rtn = NULL;
	while (1)
	{
		pos_next = ft_strnstr(pos, a, ft_strlen(str));
		if (pos_next == NULL)
		{
			rtn = ft_strnstack(rtn, pos, ft_strlen(pos));
			break ;
		}
		rtn = ft_strnstack(rtn, pos, pos_next - pos);
		rtn = ft_strnstack(rtn, b, ft_strlen(b));
		pos_next += ft_strlen(a);
		pos = pos_next;
	}
	return (rtn);
}
