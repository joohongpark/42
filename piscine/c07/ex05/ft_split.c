/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 09:49:57 by joopark           #+#    #+#             */
/*   Updated: 2020/08/13 09:49:59 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int						ft_strlen(char *str)
{
	int					len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char					*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;
	unsigned int		f;

	i = 0;
	f = 0;
	while (i < n)
	{
		if (f == 0)
		{
			if (src[i] != '\0')
				dest[i] = src[i];
			else
				f = 1;
		}
		if (f == 1)
			dest[i] = '\0';
		i++;
	}
	return (dest);
}

char					*ft_charsearch(char *str, char *chars)
{
	int					s_p;
	int					f_p;

	s_p = 0;
	while (str[s_p] != '\0')
	{
		f_p = 0;
		while (chars[f_p] != '\0')
		{
			if (str[s_p] == chars[f_p])
				break ;
			else
				f_p++;
		}
		if (chars[f_p] != '\0')
			break ;
		else
			s_p++;
	}
	return ((str[s_p] != '\0') ? (&str[s_p]) : (char *)0);
}

char					**ft_split(char *str, char *charset)
{
	char				**rtn;
	char				*s[2];
	int					p;
	int					len;

	len = ft_strlen(str);
	if (!(rtn = (char **)malloc(sizeof(char *) * (len + 1))))
		return ((char **)0);
	s[0] = str;
	p = 0;
	while (s[0] < (str + len))
	{
		s[1] = ft_charsearch(s[0], charset);
		s[1] = (s[1] == ((char *)0)) ? s[0] + ft_strlen(s[0]) : s[1];
		if ((s[1] - s[0]) > 0)
		{
			rtn[p] = (char *)malloc(sizeof(char *) * ((s[1] - s[0]) + 1));
			rtn[p][(s[1] - s[0])] = '\0';
			ft_strncpy(rtn[p], s[0], (s[1] - s[0]));
			p++;
		}
		s[0] = s[1] + 1;
	}
	rtn[p] = (char *)0;
	return (rtn);
}
