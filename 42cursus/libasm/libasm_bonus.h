/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:17:29 by joopark           #+#    #+#             */
/*   Updated: 2021/01/20 23:23:55 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int			ft_atoi_base(char *str, char *base);
void		ft_list_push_front(t_list **begin_list, void *data);
int			ft_list_size(t_list *begin_list);
void		ft_list_sort(t_list **begin_list, int (*cmp)());
void		ft_list_remove_if(t_list **begin_list, void *data_ref,
								int (*cmp)(), void (*free_fct)(void *));

#endif
