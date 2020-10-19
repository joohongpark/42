/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:47:58 by joopark           #+#    #+#             */
/*   Updated: 2020/10/19 19:48:00 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "get_next_line.h"

char				*ft_strstack(char *stack, char *str)
{
	char			*rtn;
	size_t			len;

	if (stack == NULL)
	{
		if (!(stack = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		stack[0] = '\0';
	}
	len = ft_strlen(stack) + 1;
	if (!(rtn = (char *)malloc(sizeof(char) * (len + ft_strlen(str)))))
	{
		if (str)
			free(str);
		if (stack)
			free(stack);
		return (NULL);
	}
	ft_strlcpy(rtn, stack, len);
	ft_strlcpy(rtn + len - 1, str, ft_strlen(str) + 1);
	return (rtn);
}

char				*ft_getbuf(int fd)
{
	static char		*buffer[OPEN_MAX] = {0, };

	if (buffer[fd] == NULL)
	{
		if (!(buffer[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (NULL);
		ft_memset(buffer[fd], 0, BUFFER_SIZE + 1);
	}
	return (buffer[fd]);
}

int					get_next_line(int fd, char **line)
{
	ssize_t			len;
	char			*npos;
	char			*buffer;

	len = -2;
	npos = NULL;
	if ((fd < 0) || (BUFFER_SIZE < 1) || (line == NULL) ||
		!(*line = ft_strstack(NULL, "")) || !(buffer = ft_getbuf(fd)))
		return (-1);
	while ((len != -1 && len != 0))
	{
		if (ft_strlen(buffer) == 0)
			len = read(fd, buffer, BUFFER_SIZE);
		else
		{
			if ((npos = ft_strnstr(buffer, "\n", BUFFER_SIZE)))
			{
				*npos = '\0';
				if (!(*line = ft_strstack(*line, buffer)))
					return (-1);
				*npos = '\n';
				ft_memcpy(buffer, npos + 1, ft_strlen(npos + 1) + 1);
				ft_memset(buffer + ft_strlen(buffer), 0, BUFFER_SIZE - ft_strlen(buffer));
				break;
			}
			else
			{
				if (!(*line = ft_strstack(*line, buffer)))
					return (-1);
				ft_memset(buffer, 0, BUFFER_SIZE);
			}
		}
	}
	if (len == -1)
		return (-1);
	return ((npos == NULL && len != -2) ? 0 : 1);
}
