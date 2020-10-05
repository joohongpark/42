/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:24:52 by joopark           #+#    #+#             */
/*   Updated: 2020/08/10 16:26:13 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			diff(char *c1, char *c2)
{
	int		p;

	p = 0;
	while (c1[p] != '\0' || c2[p] != '\0')
	{
		if (c1[p] == c2[p])
			p++;
		else if (c1[p] > c2[p])
			return (-1);
		else
			return (1);
	}
	if (c1[p] == '\0' && c2[p] == '\0')
		return (0);
	else if (c1[p] == '\0')
		return (-1);
	else
		return (1);
}

void		sort(char *arr[], int size)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (i++ < size)
	{
		j = -1;
		while (j++ < (size - i - 2))
		{
			if (diff(arr[j], arr[j + 1]) != 1)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int			main(int argc, char *argv[])
{
	int		len;
	int		idx;

	if (argc == 1)
		return (0);
	idx = argc - 1;
	sort(argv + 1, argc - 1);
	while (idx > 0)
	{
		len = 0;
		while (argv[argc - idx][len] != 0)
			len++;
		write(1, argv[argc - idx], len);
		write(1, "\n", 1);
		idx--;
	}
	return (0);
}
