/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:30:22 by joopark           #+#    #+#             */
/*   Updated: 2020/08/03 15:32:59 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_rev_int_tab(int *tab, int size)
{
	int		start;
	int		end;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		tab[start] ^= tab[end];
		tab[end] ^= tab[start];
		tab[start] ^= tab[end];
		start++;
		end--;
	}
}
