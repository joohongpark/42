/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:41:24 by joopark           #+#    #+#             */
/*   Updated: 2020/08/11 18:42:11 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char		*ft_strcpy(char *dest, char *src)
{
	int		p;

	p = 0;
	while (src[p] != '\0')
	{
		dest[p] = src[p];
		p++;
	}
	dest[p] = src[p];
	return (dest);
}

int			strjoinlen(int size, char **strs, char *sep)
{
	int		len;
	int		c;
	int		p;

	c = 0;
	len = 0;
	while (c < size)
	{
		len += ft_strlen(strs[c]);
		c++;
	}
	p = ft_strlen(sep);
	len += p * (((size - 1) < 1) ? 0 : (size - 1));
	return (len);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	char	*rtn;
	int		len;
	int		c;
	int		i;

	len = strjoinlen(size, strs, sep);
	if (!(rtn = (char *)malloc(sizeof(char) * (len + 1))))
		return (void *)0;
	c = -1;
	i = 0;
	while (++c < size)
	{
		ft_strcpy(&rtn[i], strs[c]);
		i += ft_strlen(strs[c]);
		if (c != (size - 1))
		{
			ft_strcpy(&rtn[i], sep);
			i += ft_strlen(sep);
		}
	}
	return (rtn);
}
