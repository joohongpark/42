/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:24:12 by joopark           #+#    #+#             */
/*   Updated: 2021/03/11 20:24:21 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int	ft_lstdupchk(t_list *lst, int element)
{
	while (lst != NULL)
	{
		if (*((int *)lst->content) == element)
			return (-1);
		lst = lst->next;
	}
	return (0);
}

int	ft_lstissort(t_list *lst)
{
	int	small;

	while (lst != NULL)
	{
		small = *((int *)lst->content);
		if (lst->next != NULL && *((int *)lst->next->content) < small)
			return (-1);
		lst = lst->next;
	}
	return (0);
}
