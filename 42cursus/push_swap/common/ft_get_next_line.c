/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:43:13 by joopark           #+#    #+#             */
/*   Updated: 2021/03/12 14:01:16 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

char	*ft_strnstack(char *stack, char *str, size_t n)
{
	char	*rtn;
	size_t	len;

	if (stack == NULL)
	{
		stack = (char *)malloc(sizeof(char) * 1);
		if (stack == NULL)
			return (NULL);
		stack[0] = '\0';
	}
	len = ft_strlen(stack);
	rtn = (char *)malloc(sizeof(char) * (len + ft_strlen(str) + 1));
	if (rtn == NULL)
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

char	*ft_getbuf(ssize_t clr, char **bp)
{
	if (*bp == NULL)
	{
		*bp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (*bp == NULL)
			return (NULL);
		ft_memset(*bp, 0, BUFFER_SIZE + 1);
	}
	if (*bp != NULL && clr == 0)
	{
		free(*bp);
		*bp = NULL;
	}
	return (*bp);
}

int	ft_prechk(int fd, char **line, char **bufrtn, char **bp)
{
	char	tmp;

	if (fd < 0)
		return (-1);
	if (read(fd, &tmp, 0) == -1)
		return (-1);
	if (BUFFER_SIZE < 1)
		return (-1);
	if (line == NULL)
		return (-1);
	*line = ft_strnstack(NULL, "", 0);
	if (*line == NULL)
		return (-1);
	*bufrtn = ft_getbuf(1, bp);
	if (*bufrtn == NULL)
		return (-1);
	return (0);
}

int	ft_getbyn(char *buf, char **line)
{
	char	*p;

	p = ft_strnstr(buf, "\n", BUFFER_SIZE);
	if (p == 0)
	{
		*line = ft_strnstack(*line, buf, ft_strlen(buf));
		ft_memset(buf, 0, BUFFER_SIZE);
	}
	else
	{
		*line = ft_strnstack(*line, buf, p - buf);
		ft_memcpy(buf, p + 1, ft_strlen(p + 1) + 1);
		ft_memset(buf + ft_strlen(buf), 0, BUFFER_SIZE - ft_strlen(buf));
	}
	if (*line == NULL)
		return (-1);
	return (p != NULL);
}

int	ft_get_next_line(int fd, char **line, char **bp)
{
	ssize_t	len;
	char	*b;
	int		tmp;

	len = -2;
	if (ft_prechk(fd, line, &b, bp) == -1)
		return (-1);
	while ((len != -1 && len != 0))
	{
		if (ft_strlen(b) == 0)
			len = read(fd, b, BUFFER_SIZE);
		else
		{
			tmp = ft_getbyn(b, line);
			if (tmp == -1)
				return (-1);
			if (tmp)
				break ;
		}
	}
	b = ft_getbuf(len, bp);
	if (len == -2 || len > 0 || (b != NULL && !len))
		return (1);
	else
		return (len);
}