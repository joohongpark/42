/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:21:22 by joopark           #+#    #+#             */
/*   Updated: 2021/03/25 20:57:30 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

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
int					ft_atoi(const char *str, int *value);

size_t				ft_strlen(char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle, size_t len);
int					ft_str_is_int(char *str);

int 				ft_lstsize(t_list *lst);
int					ft_lstdupchk(t_list *lst, int element);
int					ft_lstissort(t_list *lst);
int					ft_lstisrevsort(t_list *lst);

int					ft_lstoverval(t_list *lst, int element, int *val);
int					ft_lstdist(t_list *lst, int element);
int					ft_lstissort_len(t_list *lst, int len);
int					ft_lstisrevsort_len(t_list *lst, int len);
int					*ft_get_elem(t_list *stack, int depth);

void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);

char				*ft_strnstack(char *stack, char *str, size_t n);
char				*ft_getbuf(ssize_t clr, char **bp);
int					ft_prechk(int fd, char **line, char **bufrtn, char **bp);
int					ft_getbyn(char *buf, char **line);
int					ft_get_next_line(int fd, char **line, char **bp);

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

void				ft_insert_stack(t_list **stack_a, int argc, char *argv[]);
void				ft_err_exit(t_list **stack_a, t_list **stack_b);

int					ft_stack_sort(t_list **stack_a, t_list **stack_b, t_list **pivot);
int					ft_get_center(t_list *stack, int depth, int *val);
int					ft_a_stack_pivot(t_list **sa, t_list **sb, int n, int pivot);
int					ft_b_stack_pivot(t_list **sa, t_list **sb, int n, int pivot);
int					ft_cmd_n(t_list **sa, t_list **sb, char *cmd, int n);

int					ft_stacka_proc(t_list **sa, t_list **sb, t_list **p, int *h);
int					ft_first_pivot(t_list **sa, t_list **sb, t_list **p);
int					ft_stacka_head_swap(t_list **stack_a, t_list **stack_b);
int					ft_stacka_three_swap(t_list **stack_a, t_list **stack_b);

int					ft_stackb_pivot(t_list **sa, t_list **sb, t_list **p);
int					ft_stackb_pivot_tail(t_list **sa, t_list **sb, t_list **p);
int					ft_stackb_head_swap(t_list **stack_a, t_list **stack_b);
int					ft_stackb_three_swap(t_list **stack_a, t_list **stack_b);

void				ft_quicksort(int *data, int start, int end);
void				ft_quicksort_swap(int *a, int *b);

#endif
