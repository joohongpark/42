/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:19:31 by joopark           #+#    #+#             */
/*   Updated: 2021/03/11 00:26:08 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int	ft_deque_front_push(t_list **list, int value)
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
	ft_lstadd_front(list, lst);
	return (0);
}

int	ft_deque_front_pop(t_list **list, int *value)
{
	t_list			*element;

	if (*list == NULL)
		return (-1);
	element = *list;
	*list = element->next;
	*value = *((int *)element->content);
	ft_lstdelone(element, free);
	return (0);
}

int	ft_deque_front_peak(t_list **list, int *value)
{
	t_list			*element;

	if (*list == NULL)
		return (-1);
	element = ft_lstlast(*list);
	*value = *((int *)element->content);
	return (0);
}
