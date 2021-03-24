/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:20:02 by joopark           #+#    #+#             */
/*   Updated: 2021/03/24 17:48:43 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>
#include <stdio.h>
/**
 * deque 구조 : [list_first] - [list] - [list] - [list_end]
 * deque back 관련 연산 : list의 끝 (next 포인터가 null) 에 접근한다.
 * deque front 관련 연산 : list의 처음에 접근한다.
 * 처음 ft_insert_stack을 이용해서 a 스택에 집어 넣을 때는 back에 접근해 집어넣으므로 데이터는 왼쪽 -> 오른쪽 순서로 쌓인다.
 * 이 과제에서 사용하는 스택의 bottom은 deque의 back (list의 끝) 이며 top은 deque의 front (리스트의 시작)이다.
*/

int	test_get_center(t_list *stack, int depth, int *val)
{
	int	*list;

	list = ft_get_elem(stack, depth);
	if (list == NULL)
		return (-1);
	ft_quicksort(list, 0, depth - 1);
	*val = list[depth / 2];
	free(list);
	return (0);
}

void		ft_putnbr_fd(int n, int fd)
{
	long	tmp;
	long	base;
	char	c;

	tmp = n >= 0 ? (long)n : -1L * n;
	base = 1L;
	while ((base *= 10) < tmp)
		;
	if (n < 0)
		write(fd, "-", 1);
	while (base /= 10)
	{
		c = (tmp / base) + '0';
		write(fd, &c, 1);
		tmp = tmp % base;
	}
}

void __dump(char *memo, t_list **stack)
{
	int tmp;

	write(1, "==========", 10);
	write(1, memo, ft_strlen(memo));
	write(1, "==========\n", 11);
	while (ft_deque_front_pop(stack, &tmp) == 0)
	{
		ft_putnbr_fd(tmp, 1);
		write(1, "\n", 1);
	}
}

int	test_first_pivot(t_list **stack_a, t_list **stack_b, t_list **t_pivot)
{
	int	pivot;
	int	len;

	len = ft_lstsize(*stack_a);
	if (len < 4 || (ft_lstissort_len(*stack_a, len) == 0))
	{
		if (len == 3)
			ft_stacka_three_swap(stack_a, stack_b);
		else if (len == 2)
			ft_stacka_head_swap(stack_a, stack_b);
	}
	else
	{
		if (test_get_center(*stack_a, len, &pivot) != 0)
			return (-1);
		ft_a_stack_pivot(stack_a, stack_b, len, pivot);
		//ft_cmd_n(stack_a, stack_b, "pb", 1);
		ft_deque_front_push(t_pivot, pivot);
	}
	return (0);
}

int	test_stacka_proc(t_list **stack_a, t_list **stack_b, t_list **t_pivot, int *head)
{
	int	pivot;
	int	len;
	int	tmp;

	len = ft_lstdist(*stack_a, *head);
	if (len < 3 || (ft_lstissort_len(*stack_a, len) == 0))
	{
		if (len == 2)
			ft_stacka_three_swap(stack_a, stack_b);
		else if (len == 1)
			ft_stacka_head_swap(stack_a, stack_b);
		if (ft_deque_front_peak(stack_a, head) == -1)
			return (-1);
	}
	else
	{
		if (test_get_center(*stack_a, len, &pivot) != 0)
			return (-1);
		tmp = ft_a_stack_pivot(stack_a, stack_b, len, pivot);
		ft_cmd_n(stack_a, stack_b, "rra", tmp);
		if (ft_deque_front_peak(stack_b, &pivot) == -1)
			return (-1);
		ft_deque_front_push(t_pivot, pivot);
	}
	return (0);
}

int	test_bstack_pivot(t_list **stack_a, t_list **stack_b, t_list **pivots)
{
	int	pivot;
	int	stack_len;

	stack_len = ft_lstsize(*stack_b);
	if (stack_len == 2)
		ft_stackb_head_swap(stack_a, stack_b);
	if (stack_len == 3)
		ft_stackb_three_swap(stack_a, stack_b);
	if (stack_len > 0 && stack_len < 4)
		ft_cmd_n(stack_a, stack_b, "pa", stack_len);
	else 
	{
		if (test_get_center(*stack_b, stack_len, &pivot) != 0)
			return (-1);
		ft_b_stack_pivot(stack_a, stack_b, stack_len, pivot);
		ft_cmd_n(stack_a, stack_b, "pb", 1);
		if (ft_deque_front_push(pivots, pivot) == -1)
			return (-1);
	}
	return (0);
}

int	test_btoastack(t_list **stack_a, t_list **stack_b, t_list **pivots)
{
	int pivot;
	int	pivot_dist;

	if (ft_deque_front_pop(pivots, &pivot) == -1)
		return (-1);
	pivot_dist = ft_lstdist(*stack_b, pivot);
	if (pivot_dist == 1)
		ft_stackb_head_swap(stack_a, stack_b);
	if (pivot_dist == 2)
		ft_stackb_three_swap(stack_a, stack_b);
	if (pivot_dist >= 0 && pivot_dist < 3)
		ft_cmd_n(stack_a, stack_b, "pa", pivot_dist + 1);
	else 
	{
		ft_cmd_n(stack_a, stack_b, "pa", pivot_dist);
		if (ft_deque_front_push(pivots, pivot) == -1)
			return (-1);
	}
	return (0);
}

int				main(int argc, char *argv[])
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*pivot;
	int			stack_a_head;
	int			tmp;
	int			rtn;
	int			pivot_a_pos;
	int			i;

	(void)tmp;
	(void)rtn;
	stack_a = NULL;
	stack_b = NULL;
	pivot = NULL;
	i = 0;
	if (argc < 2)
		return (0);
	ft_insert_stack(&stack_a, argc, argv);
	//return (0);
	// 1. stack a 에 대해 정렬될때까지 pivot 나누기 수행
	while (ft_lstissort(stack_a) == -1)
		test_first_pivot(&stack_a, &stack_b, &pivot);
	if (ft_deque_front_peak(&stack_a, &stack_a_head) == -1)
		return (-1);
	
	//write(1, "====\n", 5);
	// 2. pivot 사이에 원소들이 정렬될 때 까지 (pivot 사이 원소들이 정렬되면 Pivot 원소를 pop함.)
	while (1)
	{
		//write(1, "loop\n", 5);
		pivot_a_pos = ft_lstdist(stack_a, stack_a_head);
		if (pivot_a_pos == -1 || ((pivot_a_pos == 0) && (ft_lstissort(stack_a) == -1)))
		{
			write(1, "error (pivot_a_pos == -1) or error (2-2-1)\n", 43);
			return (0);
		}
		if (pivot_a_pos == 0)
		{
			if (stack_b == NULL)
				break ;
			if (pivot == NULL)
				test_bstack_pivot(&stack_a, &stack_b, &pivot);
			else
				test_btoastack(&stack_a, &stack_b, &pivot);
		}
		else
			test_stacka_proc(&stack_a, &stack_b, &pivot, &stack_a_head);
		//ft_deque_front_push(&pivot, pivot_a);
		i++;
		if (i > 15000)
		{
 				__dump("stack_a", &stack_a);
 				__dump("stack_b", &stack_b);
 				__dump("pivot", &pivot);
		}
	}

	return (0);
}
