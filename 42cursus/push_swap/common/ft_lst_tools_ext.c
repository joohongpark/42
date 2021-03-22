/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tools_ext.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:24:12 by joopark           #+#    #+#             */
/*   Updated: 2021/03/21 14:48:06 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int	ft_lstoverval(t_list *lst, int element, int *val)
{
	t_list *tmp;

	tmp = lst;
	while (lst != NULL)
	{
		*val = *((int *)lst->content);
		if (*val == element)
		{
			if (lst == tmp)
				return (1);
			else
			{
				*val = *((int *)tmp->content);
				return (0);
			}
		}
		tmp = lst;
		lst = lst->next;
	}
	return (-1);
}

int	ft_lstdist(t_list *lst, int element)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		if (*((int *)lst->content) == element)
			return (size);
		lst = lst->next;
		size++;
	}
	return (-1);
}

int	ft_lstissort_len(t_list *lst, int len)
{
	int	small;

	while (lst != NULL && len != 0)
	{
		small = *((int *)lst->content);
		if (lst->next != NULL && *((int *)lst->next->content) < small)
			return (-1);
		lst = lst->next;
		len--;
	}
	return (0);
}

int	ft_lstisrevsort_len(t_list *lst, int len)
{
	int	big;

	while (lst != NULL && len != 0)
	{
		big = *((int *)lst->content);
		if (lst->next != NULL && *((int *)lst->next->content) > big)
			return (-1);
		lst = lst->next;
		len--;
	}
	return (0);
}
