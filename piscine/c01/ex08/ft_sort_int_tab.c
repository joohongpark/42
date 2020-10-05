/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:22:47 by joopark           #+#    #+#             */
/*   Updated: 2020/08/03 17:42:58 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;

	i = -1;
	while (i++ < size)
	{
		j = -1;
		while (j++ < (size - i - 2))
		{
			if (tab[j] > tab[j + 1])
			{
				tab[j] ^= tab[j + 1];
				tab[j + 1] ^= tab[j];
				tab[j] ^= tab[j + 1];
			}
		}
	}
}
