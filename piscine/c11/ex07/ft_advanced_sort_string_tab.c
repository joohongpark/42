/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:09:57 by joopark           #+#    #+#             */
/*   Updated: 2020/08/18 12:10:00 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		min;
	char	*swap;

	i = 0;
	while (tab[i] != ((char *)0))
	{
		j = i;
		min = i;
		while (tab[j] != ((char *)0))
		{
			if (0 < (cmp)(tab[min], tab[j]))
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
