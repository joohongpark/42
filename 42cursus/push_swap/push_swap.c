/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:20:02 by joopark           #+#    #+#             */
/*   Updated: 2021/03/23 19:47:28 by joopark          ###   ########.fr       */
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
	if (len > 3)
	{
		if (test_get_center(*stack_a, len, &pivot) != 0)
			return (-1);
		ft_deque_front_push(t_pivot, pivot);
		ft_a_stack_pivot(stack_a, stack_b, len, pivot);
		//ft_cmd_n(stack_a, stack_b, "pa", 1);
	}
	else if (len == 3 || len == 2)
	{
		if (len == 3)
			ft_stacka_three_swap(stack_a, stack_b);
		else
			ft_stacka_head_swap(stack_a, stack_b);
		if (ft_deque_front_peak(stack_a, &pivot) == -1)
			return (-1);
		ft_deque_front_push(t_pivot, pivot);
	}
	return (0);
}

int	test_bstack_pivot(t_list **stack_a, t_list **stack_b, t_list **pivots, int pivot)
{
	int	pivot_dist;

	pivot_dist = ft_lstdist(*stack_b, pivot);
	if (pivot_dist == 1)
		ft_stackb_head_swap(stack_a, stack_b);
	if (ft_lstissort_len(*stack_b, pivot_dist) != 0)
	{
		ft_b_stack_pivot(stack_a, stack_b, pivot_dist, pivot);
		if (pivot_dist != 0)
		{
			if (ft_deque_front_push(pivots, pivot) == -1)
				return (-1);
		}
	}
	else
	{
		while (pivot_dist)
		{
			if (pivot_dist != 1)
				ft_cmd_n(stack_a, stack_b, "rrb", 1);
			ft_cmd_n(stack_a, stack_b, "pa", 1);
			pivot_dist--;
		}
	}
	return (0);
}

int	test_bstack_pivot_exist(t_list **stack_a, t_list **stack_b, t_list **pivots)
{
	int pivot;
	int	pivot_over;

	if (ft_deque_front_peak(pivots, &pivot) == -1)
		return (-1);
	if (ft_lstdist(*stack_b, pivot) == 0)
	{
		if (ft_deque_front_pop(pivots, &pivot) == -1)
			return (-1);
		ft_cmd_n(stack_a, stack_b, "pa", 1);
	}
	else
	{
		if (ft_lstoverval(*stack_b, pivot, &pivot_over) == 0)
		{
			if (ft_deque_front_pop(pivots, &pivot) == -1)
				return (-1);
		}
		test_bstack_pivot(stack_a, stack_b, pivots, pivot);
	}
	return (0);
}

int				main(int argc, char *argv[])
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*pivot;
	t_list		*pivot_between_ab;
	int			tmp;
	int			tmp1;
	int			pivot_over;
	int			dist;
	int			rtn;
	int			pivot_a;
	int			pivot_a_pos;
	int			pivot_b;
	int			i;

	(void)tmp;
	(void)rtn;
	stack_a = NULL;
	stack_b = NULL;
	pivot = NULL;
	pivot_between_ab = NULL;
	i = 0;
	if (argc < 2)
		return (0);
	ft_insert_stack(&stack_a, argc, argv);
	// 0. 전처리
	ft_stack_pre(&stack_a, &stack_b);
	//return (0);
	// 1. stack a 에 대해 정렬될때까지 pivot 나누기 수행
	while (ft_lstissort(stack_a) == -1)
		test_first_pivot(&stack_a, &stack_b, &pivot);
	if (ft_deque_front_peak(&stack_a, &tmp) == -1)
		return (-1);
	if (ft_deque_front_peak(&pivot, &tmp1) == -1)
	{
		if (ft_deque_front_push(&stack_a, tmp) == -1)
			return (-1);
	}
	else
	{
		if (tmp != tmp1)
			ft_cmd_n(&stack_a, &stack_b, "pa", 1);
	}
	// 2. pivot 사이에 원소들이 정렬될 때 까지 (pivot 사이 원소들이 정렬되면 Pivot 원소를 pop함.)
	while (pivot != NULL || pivot_between_ab != NULL)
	{
		if (ft_deque_front_pop(&pivot, &pivot_a) == -1)
			return (-1);
		pivot_a_pos = ft_lstdist(stack_a, pivot_a);
		if (pivot_a_pos == -1)
		{
			write(1, "error (pivot_a_pos == -1)\n", 26);
			return (0);
		}
		else if (pivot_a_pos == 0)
		{
			if (ft_lstissort(stack_a) == -1)
			{
				write(1, "error (2-2-1)\n", 14);
				return (0);
			}
			else
			{
				if (ft_lstisrevsort(stack_b) == 0)
				{
					tmp = ft_lstsize(stack_b);
					ft_cmd_n(&stack_a, &stack_b, "pa", tmp);
					break ;
				}
				if (pivot == NULL && pivot_between_ab == NULL)
				{
					if (ft_deque_back_peak(&stack_b, &pivot_b) == -1)
						return (-1);
					test_bstack_pivot(&stack_a, &stack_b, &pivot_between_ab, pivot_b);
				}
				else if (pivot_between_ab != NULL)
					test_bstack_pivot_exist(&stack_a, &stack_b, &pivot_between_ab);
				else
					test_bstack_pivot_exist(&stack_a, &stack_b, &pivot);
			}
		}
		// 2-3. 만약 pivot 스택의 top이 a 스택의 top의 바로 밑 값이라면 -> 여기서 pivot은 무조건 top보다 원소 하나만큼 큼
		else if (pivot_a_pos == 1)
		{
			ft_stacka_head_swap(&stack_a, &stack_b);
			if (ft_deque_front_peak(&stack_a, &pivot_a) == -1)
				return (-1);
		}
		else if (pivot_a_pos == 2)
		{
			ft_stacka_three_swap(&stack_a, &stack_b);
			if (ft_deque_front_peak(&stack_a, &pivot_a) == -1)
				return (-1);
		}
		// 2-4. 만약 pivot 스택의 top이 a 스택의 top과 차이가 2 이상 난다면 -> a 스택 pivot
		else
		{
			if (ft_lstoverval(stack_a, pivot_a, &pivot_over) == -1)
				return (-1);
			dist = pivot_a_pos - 1;
			if (ft_lstissort_len(stack_a, dist + 1) == 0)
			{
				if (ft_deque_front_peak(&stack_a, &pivot_a) == -1)
					return (-1);
			}
			else
			{
				tmp = ft_a_stack_pivot(&stack_a, &stack_b, dist, pivot_over);
				if (dist > 0)
				{
					ft_cmd_n(&stack_a, &stack_b, "pb", 1);
				}
				ft_cmd_n(&stack_a, &stack_b, "rra", tmp);
				// a 스택과 b 스택 사이에 있는 피봇 추가
				if (ft_deque_front_peak(&stack_b, &pivot_b) == -1)
					return (-1);
				ft_deque_front_push(&pivot_between_ab, pivot_b);
			}
		}
		ft_deque_front_push(&pivot, pivot_a);
		i++;
		if (i > 15000)
		{
 				__dump("stack_a", &stack_a);
 				__dump("stack_b", &stack_b);
 				__dump("pivot", &pivot);
 				__dump("pivot_between_ab", &pivot_between_ab);
		}
	}

	return (0);
}
