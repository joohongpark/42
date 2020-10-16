/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:10:58 by joopark           #+#    #+#             */
/*   Updated: 2020/10/16 00:41:26 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 5

int					get_next_line(int fd, char **line)
{
	static char		buffer[BUFFER_SIZE + 1] = {0, };
	size_t			readlen;
	char			*test;

	**line = '\0';
	while (1)
	{
		readlen = read(fd, buffer, BUFFER_SIZE);
		if (readlen == 0)
			break ;
		test = ft_strnstr(buffer, "\n", readlen);
		if (test)
		{
			ft_strlcpy(*line, buffer, test - buffer + 1);
			break ;
		}
		else
		{
			ft_strlcpy(*line, buffer, readlen + 1);
			break ;
		}
	}
	return ((readlen == 0) ? 0 : 1);
	/*
	char			*tmp;
	size_t			buflen;

	*line = NULL;
	buflen = ft_strlen(buffer);
	if (buflen != 0)
	{
		if (*line == NULL)
		{
			ft_strnstr
		}
		*tmp = ft_strjoin(, buffer);
	}
	else
	{
		// 이거도 개행이 나올때까지 위와 유사하게
	}
	*/
	
}
