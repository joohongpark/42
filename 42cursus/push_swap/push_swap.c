/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:20:02 by joopark           #+#    #+#             */
/*   Updated: 2021/03/15 23:02:08 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>
#include <stdio.h>

int	test_first_pivot(t_list **stack_a, t_list **stack_b, t_list **t_pivot)
{
	int	pivot;
	int	tmp;
	int	op_result;

	if (ft_deque_front_peak(stack_a, &pivot) == -1)
		return (-1);
	ft_deque_front_push(t_pivot, pivot);
	while (1)
	{
		if (ft_deque_back_peak(stack_a, &tmp) == -1)
			return (-1);
		if (pivot == tmp)
			break ;
		if (pivot < tmp)
		{
			op_result = ft_op(stack_a, stack_b, "ra");
			printf("ra\n");
		}
		else
		{
			op_result = ft_op(stack_a, stack_b, "pb");
			printf("pb\n");
		}
		if (op_result != 0)
			return (-1);
	}
	return (0);
}

int	ft_check_ps_none(t_list **stack_b, int pivot)
{
	int	elem;

	if (ft_deque_front_peak(stack_b, &elem) != 0)
		return (-1);
	if (elem == pivot)
		return (0);
	return (-1);
}

int	ft_check_ps_one(t_list **stack_b, int pivot)
{
	int	elem[2];

	if (ft_deque_front_pop(stack_b, &elem[0]) != 0)
		return (-1);
	if (ft_deque_front_peak(stack_b, &elem[1]) != 0)
		return (-1);
	if (ft_deque_front_push(stack_b, elem[0]) != 0)
		return (-1);
	if (elem[1] == pivot)
		return (0);
	return (1);
}

int	ft_check_ps_two(t_list **stack_b, int pivot)
{
	int	elem[3];

	if (ft_deque_front_pop(stack_b, &elem[0]) != 0)
		return (-1);
	if (ft_deque_front_pop(stack_b, &elem[1]) != 0)
		return (-1);
	if (ft_deque_front_peak(stack_b, &elem[2]) != 0)
		return (-1);
	if (ft_deque_front_push(stack_b, elem[1]) != 0)
		return (-1);
	if (ft_deque_front_push(stack_b, elem[0]) != 0)
		return (-1);
	if (elem[2] == pivot)
		return (0);
	return (1);
}

int	test_bstack_pre(t_list **stack_a, t_list **stack_b, t_list **t_pivot)
{
	int	pivot[2];

	(void)stack_a;
	if (ft_deque_front_pop(t_pivot, &pivot[0]) != 0)
		return (-1);
	if (ft_deque_front_pop(t_pivot, &pivot[1]) != 0)
	{
		printf("fin\n");
		return (0);
	}
	if (ft_check_ps_none(stack_b, pivot[1]) == 0)
		printf("case 1\n");
	if (ft_check_ps_one(stack_b, pivot[1]) == 0)
		printf("case 2\n");
	if (ft_check_ps_two(stack_b, pivot[1]) == 0)
		printf("case 3\n");
	printf("case 4\n");
	return (0);
}

int	test_bstack_pivot(t_list **stack_a, t_list **stack_b, t_list **t_pivot)
{
	int	pivot_a;
	int	pivot_b;
	int	cnt;

	(void)stack_a;
	(void)stack_b;
	if (ft_deque_front_pop(t_pivot, &pivot_a) != 0)
		return (-1);
	if (ft_deque_front_peak(t_pivot, &pivot_b) != 0)
		return (-1);
	cnt = 0;
	printf("p1 : %d, p2 : %d\n", pivot_a, pivot_b);
	return (0);
}

int				main(int argc, char *argv[])
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*pivot;
	int			tmp;
	int			rtn;


	(void)tmp;
	(void)rtn;
	stack_a = NULL;
	stack_b = NULL;
	pivot = NULL;
	if (argc < 2)
		return (0);
	ft_insert_stack(&stack_a, argc, argv);
	while (ft_lstissort(stack_a) == -1)
		test_first_pivot(&stack_a, &stack_b, &pivot);
	test_bstack_pre(&stack_a, &stack_b, &pivot);

	/*
	while (ft_deque_front_pop(&pivot, &tmp) == 0)
		printf("pivot : %d\n", tmp);
	*/
	return (0);
}
