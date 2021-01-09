/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:44:23 by joopark           #+#    #+#             */
/*   Updated: 2020/08/09 13:01:46 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			isvaild(char *data)
{
	int		p;
	int		size;

	p = 0;
	while (data[p] != '\0')
	{
		if (data[p] != ' ' && (data[p] < '0' && data[p] > '9'))
			return (-1);
		p++;
	}
	size = (p / 2 + 1) / 4;
	p = 0;
	while (data[p] != '\0')
	{
		if ((size + '0') < data[p])
			return (-1);
		p++;
	}
	if ((p / 2 + 1) % 4 != 0)
		return (-1);
	return (size);
}

char		**parser(char *data)
{
	char	**rtn;
	int		size;
	int		i;
	int		j;

	size = isvaild(data);
	if (size == -1)
		return ((char **)0);
	i = 0;
	rtn = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		rtn[i] = (char*)malloc(sizeof(char) * (size + 1));
		j = 0;
		while (j < size)
		{
			rtn[i][j] = data[(i * (size * 2)) + (j * 2)];
			j++;
		}
		rtn[i][j] = '\0';
		i++;
	}
	return (rtn);
}
