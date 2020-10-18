/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:10:58 by joopark           #+#    #+#             */
/*   Updated: 2020/10/17 01:12:10 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
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

    *line = NULL;
    while (1)
    {
        if (ft_strlen(buffer) == 0)
            len = read(fd, buffer, BUFFER_SIZE);
        else
        {
            if ((npos = ft_strnstr(buffer, "\n", len)))
            {
                *npos = '\0';
                *line = ft_strstack(*line, buffer);
                ft_memcpy(buffer, npos + 1, ft_strlen(npos + 1) + 1);
                break ;
            }
            else
            {
                *line = ft_strstack(*line, buffer);
                ft_memset(buffer, 0, BUFFER_SIZE);
            }
        }
        if (len <= 0)
            break ;
    }
    return ((len == 0) ? 0 : 1);
}
