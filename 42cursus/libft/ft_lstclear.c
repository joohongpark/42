/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 07:18:45 by joopark           #+#    #+#             */
/*   Updated: 2020/10/09 16:24:53 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	if (lst != NULL && *lst != NULL)
	{
		while ((*lst)->next != NULL)
		{
			del((*lst)->content);
			tmp = (*lst);
			(*lst) = (*lst)->next;
			free(tmp);
		}
	}
	free((*lst));
}
