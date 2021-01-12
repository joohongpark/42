/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lifo_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:02:51 by joopark           #+#    #+#             */
/*   Updated: 2021/01/12 01:57:52 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_vector			ft_push(t_list **list, t_vector v)
{
	t_vector		*insert;
	t_list			*lst;

	if (!(insert = (t_vector *)malloc(sizeof(t_vector))))
		return (ft_vinit(-1, -1));
	insert->x = v.x;
	insert->y = v.y;
	lst = ft_lstnew(insert);
	if (lst != NULL)
		ft_lstadd_front(list, lst);
	else
		*list = lst;
	return (v);
}

t_vector			ft_pop(t_list **list)
{
	t_vector		rtn;
	t_vector		*get;
	t_list			*lst;

	if (*list == NULL)
		return (ft_vinit(-1, -1));
	lst = *list;
	get = lst->content;
	*list = lst->next;
	rtn = ft_vinit(get->x, get->y);
	ft_lstdelone(lst, free);
	return (rtn);
}
