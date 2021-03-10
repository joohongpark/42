/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:19:31 by joopark           #+#    #+#             */
/*   Updated: 2021/03/10 18:17:12 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int					ft_deque_back_push(t_list **list, int value)
{
	t_list			*lst;
	int				*insert;

	insert = (int *)malloc(sizeof(int));
	if (insert == NULL)
		return (-1);
	*insert = value;
	lst = ft_lstnew(insert);
	if (lst == NULL)
		return (-1);
	ft_lstadd_back(list, lst);
	return (0);
}

int					ft_deque_back_pop(t_list **list, int *value)
{
	t_list			*element;
	t_list			*element_tmp;

	if (*list == NULL)
		return (-1);
	element = ft_lstlast(*list);
	element_tmp = *list;
	if (element != element_tmp)
	{
		while (element_tmp->next != element)
			element_tmp = element_tmp->next;
		element_tmp->next = NULL;
	}
	else
	{
		*list = NULL;
	}
	*value = *((int *)element->content);
	ft_lstdelone(element, free);
	return (0);
}

int					ft_deque_back_peak(t_list **list, int *value)
{
	if (*list == NULL)
		return (-1);
	*value = *((int *)(*list)->content);
	return (0);
}
