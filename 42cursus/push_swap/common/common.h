/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:21:22 by joopark           #+#    #+#             */
/*   Updated: 2021/03/10 23:37:26 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_strncmp(const char *s1, const char *s2, size_t n);

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);

int					ft_deque_back_push(t_list **list, int value);
int					ft_deque_back_pop(t_list **list, int *value);
int					ft_deque_back_peak(t_list **list, int *value);
int					ft_deque_front_push(t_list **list, int value);
int					ft_deque_front_pop(t_list **list, int *value);
int					ft_deque_front_peak(t_list **list, int *value);

int					ft_op(t_list **stack_a, t_list **stack_b, char *op);
int					ft_swap(t_list **stack);
int					ft_push(t_list **stacka, t_list **stackb);
int					ft_rotate(t_list **stack);
int					ft_reverse_rotate(t_list **stack);

#endif
