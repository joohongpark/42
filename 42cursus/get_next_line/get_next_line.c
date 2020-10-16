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

#define BUFFER_SIZE 3

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
	size_t			readlen;
	char			*test;
	int	i = 0;

	*line = NULL;
	while (1)
	{
		//printf("%d\n", i);
		if (i++ > 10)
			break;
		if (readlen == 0)
			break;
		if (ft_strlen(buffer) == 0)
			readlen = read(fd, buffer, BUFFER_SIZE);
		else
		{
			printf("[%s/%s]\n", *line, buffer);
			if (test = ft_strnstr(buffer, "\n", readlen))
			{
				//printf("[%s/%s]\n", buffer, test);
				*test = '\0';
				*line = ft_strstack(*line, buffer);
				if (test - buffer)
					ft_memcpy(buffer, test - buffer + 1, ft_strlen(test - buffer) + 1);
				break;
			}
			else
			{
				*line = ft_strstack(*line, buffer);
				ft_memset(buffer, 0, BUFFER_SIZE);
			}
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
