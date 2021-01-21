/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:21:08 by joopark           #+#    #+#             */
/*   Updated: 2021/01/21 09:28:29 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libasm_bonus.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>

void		ft_atoi_base_test(void);
void		ft_list_push_front_test(void);
void		ft_list_size_test(void);
void		ft_list_sort_test(void);
void		ft_list_remove_if_test(void);

void ft_list_remove_if1(t_list **begin_list, void *data_ref,
							int (*cmp)(), void (*free_fct)(void *));
void ft_list_remove_if1(t_list **begin_list, void *data_ref,
							int (*cmp)(), void (*free_fct)(void *))
{
	t_list *saved_next;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	if (cmp((*begin_list)->data, data_ref) != 0)
	{
		ft_list_remove_if1(&(*begin_list)->next, data_ref, cmp, free_fct);
		return ;
	}
	saved_next = (*begin_list)->next;
	free_fct((*begin_list)->data);
	free(*begin_list);
	*begin_list = saved_next;
	ft_list_remove_if1(begin_list, data_ref, cmp, free_fct);
}
void	ft_list_remove_if2(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*list;
	t_list	*list2;
	t_list	*tmp;

	list = *begin_list;
	while (list && list->next)
	{
		if ((*cmp)(list->next->data, data_ref) == 0)
		{
			tmp = list->next;
			list->next = list->next->next;
			(*free_fct)(tmp->data);
			free(tmp);
		}
		list = list->next;
	}
	list2 = *begin_list;
	if (list2 && (*cmp)(list2->data, data_ref) == 0)
	{
		*begin_list = list2->next;
		(*free_fct)(list2->data);
		free(list2);
		*begin_list = NULL;
	}
}

int		_cmp(void *i, void *j)
{
	return *(int*)i - *(int*)j;
	//return (*((int *)i) > *((int *)j));
}

int main (void)
{
	ft_atoi_base_test();
	ft_list_push_front_test();
	ft_list_size_test();
	ft_list_sort_test();
	ft_list_remove_if_test();
	return (0);
}

void		ft_atoi_base_test(void)
{
	printf("%d\n", ft_atoi_base("", ""));
	printf("%d\n", ft_atoi_base("10", ""));
	printf("%d\n", ft_atoi_base("10111", "\t541"));
	printf("%d\n", ft_atoi_base("x 1234", "0123456789"));
	printf("%d\n", ft_atoi_base("4321s", "0123456789"));
	printf("%d\n", ft_atoi_base("-123456789", "0123456789"));
	printf("%d\n", ft_atoi_base("+2147483647", "0123456789"));
	printf("%d\n", ft_atoi_base("-2147483648", "0123456789"));
}

void		ft_list_push_front_test(void)
{
	t_list	*t;
	t_list	*t1;
	char	*c1 = "data #1";
	char	*c2 = "data #2";
	t = NULL;

	ft_list_push_front(&t, c1);
	ft_list_push_front(&t, c2);
	t1 = t->next;
	printf("t_list.data : %s\tt_list.next : %p\n", ((char *)(t1->data)), t1->next);
	printf("t_list.data : %s\tt_list.next : %p\n", ((char *)(t->data)), t->next);
}

void		ft_list_size_test(void)
{
	t_list	*t;
	char	*c1 = "data #1";
	char	*c2 = "data #2";
	t = NULL;

	ft_list_push_front(&t, c1);
	ft_list_push_front(&t, c2);
	printf("list size : %d\n", ft_list_size(t));
}

void		ft_list_sort_test(void)
{
	t_list	*t;
	t_list	*p;
	int		arr[9] = {23, 34, 232, -1, 1, 45, 12, 12, 98};
	t = NULL;
	for (int i = 0; i < 9; i++)
	{
		ft_list_push_front(&t, &arr[i]);
	}
	printf("list size : %d\n", ft_list_size(t));
	p = t;
	printf("before\n");
	while (p != NULL)
	{
		printf("data : %d\n", *((int *)(p->data)));
		p = p->next;
	}
	ft_list_sort(&t, _cmp);
	p = t;
	printf("after\n");
	while (p != NULL)
	{
		printf("data : %d\n", *((int *)(p->data)));
		p = p->next;
	}
}

void		ft_list_remove_if_test(void)
{
	t_list	*t;
	t_list	*p;
	t = NULL;

	ft_list_push_front(&t, strdup("String #2"));
	ft_list_push_front(&t, strdup("String #2"));
	ft_list_push_front(&t, strdup("String #2"));
	ft_list_push_front(&t, strdup("String #2"));
	printf("list size : %d\n", ft_list_size(t));
	printf("before\n");
	p = t;
	while (p != NULL)
	{
		printf("data : [%s]\n", ((char *)(p->data)));
		p = p->next;
	}
	//ft_list_sort(&t, _cmp);
	ft_list_remove_if(&t, "String #2", strcmp, free);
	printf("after\n");
	p = t;
	while (p != NULL)
	{
		printf("data : [%s]\n", ((char *)(p->data)));
		p = p->next;
	}
}
