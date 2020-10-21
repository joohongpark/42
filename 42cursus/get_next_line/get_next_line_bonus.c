/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:47:58 by joopark           #+#    #+#             */
/*   Updated: 2020/10/21 20:35:29 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char				*ft_strnstack(char *stack, char *str, size_t n)
{
	char			*rtn;
	size_t			len;

	if (stack == NULL)
	{
		if (!(stack = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		stack[0] = '\0';
	}
	len = ft_strlen(stack);
	if (!(rtn = (char *)malloc(sizeof(char) * (len + ft_strlen(str) + 1))))
	{
		if (stack)
			free(stack);
		return (NULL);
	}
	ft_strlcpy(rtn, stack, len + 1);
	ft_strlcpy(rtn + len, str, n + 1);
	free(stack);
	rtn[len + n] = '\0';
	return (rtn);
}

char				*ft_getbuf(int fd, ssize_t clr)
{
	static char		*buffer[OPEN_MAX] = {0, };

	if (buffer[fd] == NULL)
	{
		if (!(buffer[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (NULL);
		ft_memset(buffer[fd], 0, BUFFER_SIZE + 1);
	}
	if (buffer[fd] != NULL && clr == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (buffer[fd]);
}

int					ft_prechk(int fd, char **line, char **bufrtn)
{
	if (fd < 0)
		return (-1);
	if (BUFFER_SIZE < 1)
		return (-1);
	if (line == NULL)
		return (-1);
	if (!(*line = ft_strnstack(NULL, "", 0)))
		return (-1);
	if (!(*bufrtn = ft_getbuf(fd, 1)))
		return (-1);
	return (0);
}

int					get_next_line(int fd, char **line)
{
	ssize_t			len;
	char			*p;
	char			*b;

	len = -2;
	if (ft_prechk(fd, line, &b) == -1)
		return (-1);
	while ((len != -1 && len != 0))
	{
		if (ft_strlen(b) == 0)
			len = read(fd, b, BUFFER_SIZE);
		else
		{
			p = ft_strnstr(b, "\n", BUFFER_SIZE);
			if (!(*line = ft_strnstack(*line, b, p ? (p - b) : ft_strlen(b))))
				return (-1);
			ft_memcpy(b, p + 1, p ? (ft_strlen(p + 1) + 1) : 0);
			ft_memset(b + (p ? ft_strlen(b) : 0), 0,
				BUFFER_SIZE - (p ? ft_strlen(b) : 0));
			if (p)
				break ;
		}
	}
	ft_getbuf(fd, len);
	return ((len == -2 || len > 0 || (ft_strlen(b) != 0 && !len)) ? 1 : len);
}
