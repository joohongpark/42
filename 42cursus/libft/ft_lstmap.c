/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:04:36 by joopark           #+#    #+#             */
/*   Updated: 2020/10/09 19:04:37 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*rtn;
	t_list	*rtntmp;

	rtn = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (f(lst->content) != NULL)
		{
			if (!(rtntmp = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&rtn, del);
				return (NULL);
			}
			ft_lstadd_back(&rtn, rtntmp);
		}
		else
		{
			ft_lstclear(&rtn, del);
			return (NULL);
		}
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (rtn);
}
/*
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list  *new_head;
	t_list  *new_next;
	t_list  *curr;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	if ((new_head = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	curr = new_head;
	lst = lst->next;
	while (lst)
	{
		if ((new_next = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		curr->next = new_next;
		curr = new_next;
		lst = lst->next;
	}
	return (new_head);
}
*/