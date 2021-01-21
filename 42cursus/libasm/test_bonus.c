/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:21:08 by joopark           #+#    #+#             */
/*   Updated: 2021/01/21 09:56:36 by joopark          ###   ########.fr       */
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

int		_cmp(void *i, void *j)
{
	return (*((int *)i) > *((int *)j));
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
	printf("\x1b[32m[ft_atoi_base test]\x1b[0m\n");
	printf("%d\n", ft_atoi_base("", ""));
	printf("%d\n", ft_atoi_base("10", ""));
	printf("%d\n", ft_atoi_base("10111", "\t541"));
	printf("%d\n", ft_atoi_base("x 1234", "0123456789"));
	printf("%d\n", ft_atoi_base("4321s", "0123456789"));
	printf("%d\n", ft_atoi_base("-123456789", "0123456789"));
	printf("%d\n", ft_atoi_base("+2147483647", "0123456789"));
	printf("%d\n", ft_atoi_base("-2147483648", "0123456789"));
	printf("\x1b[32m[ft_atoi_base test finish]\x1b[0m\n");
}

void		ft_list_push_front_test(void)
{
	t_list	*t;
	t_list	*t1;
	char	*c1 = "data #1";
	char	*c2 = "data #2";
	t = NULL;
	printf("\x1b[32m[ft_list_push_front test]\x1b[0m\n");

	ft_list_push_front(&t, c1);
	ft_list_push_front(&t, c2);
	t1 = t->next;
	printf("t_list.data : %s\tt_list.next : %p\n", ((char *)(t1->data)), t1->next);
	printf("t_list.data : %s\tt_list.next : %p\n", ((char *)(t->data)), t->next);
	printf("\x1b[32m[ft_list_push_front test finish]\x1b[0m\n");
}

void		ft_list_size_test(void)
{
	t_list	*t;
	char	*c1 = "data #1";
	char	*c2 = "data #2";
	t = NULL;
	printf("\x1b[32m[ft_list_size_test test]\x1b[0m\n");

	ft_list_push_front(&t, c1);
	ft_list_push_front(&t, c2);
	printf("list size : %d\n", ft_list_size(t));
	printf("\x1b[32m[ft_list_size_test test finish]\x1b[0m\n");
}

void		ft_list_sort_test(void)
{
	t_list	*t;
	t_list	*p;
	int		arr[9] = {23, 34, 232, -1, 1, 45, 12, 12, 98};
	t = NULL;
	printf("\x1b[32m[ft_list_sort test]\x1b[0m\n");
	for (int i = 0; i < 9; i++)
	{
		ft_list_push_front(&t, &arr[i]);
	}
	p = t;
	printf("\x1b[35mbefore\x1b[0m\n");
	while (p != NULL)
	{
		printf("data : %d\n", *((int *)(p->data)));
		p = p->next;
	}
	ft_list_sort(&t, _cmp);
	p = t;
	printf("\x1b[36mafter\x1b[0m\n");
	while (p != NULL)
	{
		printf("data : %d\n", *((int *)(p->data)));
		p = p->next;
	}
	printf("\x1b[32m[ft_list_sort test finish]\x1b[0m\n");
}

void		ft_list_remove_if_test(void)
{
	t_list	*t;
	t_list	*p;
	t = NULL;

	printf("\x1b[32m[ft_list_remove_if test]\x1b[0m\n");
	ft_list_push_front(&t, strdup("String #2"));
	ft_list_push_front(&t, strdup("String #2"));
	ft_list_push_front(&t, strdup("String #2"));
	ft_list_push_front(&t, strdup("String #2"));
	printf("list size : %d\n", ft_list_size(t));
	printf("\x1b[35mbefore\x1b[0m\n");
	p = t;
	while (p != NULL)
	{
		printf("data : [%s]\n", ((char *)(p->data)));
		p = p->next;
	}
	//ft_list_sort(&t, _cmp);
	ft_list_remove_if(&t, "String #2", strcmp, free);
	printf("\x1b[36mafter\x1b[0m\n");
	p = t;
	while (p != NULL)
	{
		printf("data : [%s]\n", ((char *)(p->data)));
		p = p->next;
	}
	printf("\x1b[32m[ft_list_remove_if test finish]\x1b[0m\n");
}
