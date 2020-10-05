/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 10:51:48 by joopark           #+#    #+#             */
/*   Updated: 2020/08/18 10:51:50 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strdiff(char *a, char *b)
{
	int			i;

	i = 0;
	while (a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] == b[i])
			i++;
		else
			break ;
	}
	return (a[i] - b[i]);
}

void			ft_sort_string_tab(char **tab)
{
	int			i;
	int			j;
	int			min;
	char		*swap;

	i = 0;
	while (tab[i] != ((char *)0))
	{
		j = i;
		min = i;
		while (tab[j] != ((char *)0))
		{
			if (0 < ft_strdiff(tab[min], tab[j]))
				min = j;
			j++;
		}
		if (min != i)
		{
			swap = tab[min];
			tab[min] = tab[i];
			tab[i] = swap;
		}
		i++;
	}
}
