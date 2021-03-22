/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 01:56:07 by joopark           #+#    #+#             */
/*   Updated: 2021/03/22 02:02:39 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

void	ft_quicksort(int *data, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = start;
	i = pivot + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (i <= end && data[i] <= data[pivot])
			i++;
		while (j > start && data[j] >= data[pivot])
			j--;
		if (i > j)
			ft_quicksort_swap(&data[j], &data[pivot]);
		else
			ft_quicksort_swap(&data[i], &data[j]);
	}
	ft_quicksort(data, start, j - 1);
	ft_quicksort(data, j + 1, end);
}

void	ft_quicksort_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
