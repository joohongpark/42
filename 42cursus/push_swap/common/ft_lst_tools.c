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

int ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		rtn;

	rtn = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		rtn++;
	}
	return (rtn);
}

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

int	ft_lstisrevsort(t_list *lst)
{
	int	big;

	while (lst != NULL)
	{
		big = *((int *)lst->content);
		if (lst->next != NULL && *((int *)lst->next->content) > big)
			return (-1);
		lst = lst->next;
	}
	return (0);
}

int	ft_lstprevval(t_list *lst, int element, int *val)
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
