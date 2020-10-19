/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:10:58 by joopark           #+#    #+#             */
/*   Updated: 2020/10/19 01:22:19 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

char                *ft_strstack(char *stack, char *str)
{
	char            *rtn;
	size_t            len;

	if (stack == NULL)
	{
		len = ft_strlen(str) + 1;
		if (!(rtn = (char *)malloc(sizeof(char) * len)))
			return (NULL);
		ft_strlcpy(rtn, str, len);
	}
	else
	{
		len = ft_strlen(stack) + 1;
		if (!(rtn = (char *)malloc(sizeof(char) * (len + ft_strlen(str)))))
			return (NULL);
		ft_strlcpy(rtn, stack, len);
		ft_strlcpy(rtn + len - 1, str, ft_strlen(str) + 1);
	}
	return (rtn);
}

int					get_next_line(int fd, char **line)
{
	static char		buffer[BUFFER_SIZE + 1] = {0, };
	ssize_t			len;
	char			*npos;

	len = -2;
	npos = NULL;
	if (!(*line = ft_strstack(NULL, "")) || (fd < 0))
		return (-1);
	while (1)
	{
		if (ft_strlen(buffer) == 0)
			len = read(fd, buffer, BUFFER_SIZE);
		else
		{
			if ((npos = ft_strnstr(buffer, "\n", BUFFER_SIZE)))
				*npos = '\0';
			if (!(*line = ft_strstack(*line, buffer)))
				return (-1);
			if (npos)
				*npos = '\n';
			if (npos)
				ft_memcpy(buffer, npos + 1, ft_strlen(npos + 1) + 1);
			else
				ft_memset(buffer, 0, BUFFER_SIZE);
			if (npos)
				break ;
		}
		if (len == -1 || len == 0)
			break ;
	}
	if (len == -1)
		return (-1);
	return ((npos == NULL && len != -2) ? 0 : 1);
}
