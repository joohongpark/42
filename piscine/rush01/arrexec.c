/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrexec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:46:29 by joopark           #+#    #+#             */
/*   Updated: 2020/08/09 13:47:46 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void		print(char **arr, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			write(1, &arr[i][j], 1);
			if (j != (size - 1))
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

char		**arrinit(int size)
{
	char	**rtn;
	int		i;
	int		j;

	rtn = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		rtn[i] = (char *)malloc(sizeof(char) * (size + 1));
		j = 0;
		while (j < size)
		{
			rtn[i][j] = '0';
			j++;
		}
		rtn[i][j] = '\0';
		i++;
	}
	return (rtn);
}

void		twoarrfree(char **arr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
