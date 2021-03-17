/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:20:02 by joopark           #+#    #+#             */
/*   Updated: 2021/03/17 21:00:56 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>
#include <stdio.h>

int	test_first_pivot(t_list **stack_a, t_list **stack_b, t_list **t_pivot)
{
	int	pivot;

	if (ft_deque_front_peak(stack_a, &pivot) == -1)
		return (-1);
	ft_deque_front_push(t_pivot, pivot);
	return (ft_a_stack_pivot(stack_a, stack_b, ft_lstsize(*stack_a) - 1, pivot));
}

int	ft_check_ps_none(t_list **stack, int pivot)
{
	int	elem;

	if (ft_deque_back_peak(stack, &elem) != 0)
		return (-1);
	if (elem == pivot)
		return (0);
	return (-1);
}

int	ft_check_ps_one(t_list **stack, int pivot)
{
	int	elem[2];

	if (ft_deque_back_pop(stack, &elem[0]) != 0)
		return (-1);
	if (ft_deque_back_peak(stack, &elem[1]) != 0)
		return (-1);
	if (ft_deque_back_push(stack, elem[0]) != 0)
		return (-1);
	if (elem[1] == pivot)
		return (0);
	return (1);
}

int	ft_check_ps_two(t_list **stack, int pivot)
{
	int	elem[3];

	if (ft_deque_back_pop(stack, &elem[0]) != 0)
		return (-1);
	if (ft_deque_back_pop(stack, &elem[1]) != 0)
		return (-1);
	if (ft_deque_back_peak(stack, &elem[2]) != 0)
		return (-1);
	if (ft_deque_back_push(stack, elem[1]) != 0)
		return (-1);
	if (ft_deque_back_push(stack, elem[0]) != 0)
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
	int			pivot_a;
	int			pivot_b;
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
	// 1. stack a 에 대해 정렬될때까지 pivot 나누기 수행
	while (ft_lstissort(stack_a) == -1)
		test_first_pivot(&stack_a, &stack_b, &pivot);
	// 2. pivot 사이에 원소들이 정렬될 때 까지 (pivot 사이 원소들이 정렬되면 Pivot 원소를 pop함.)
	while (pivot != NULL)
	{




		
		// pivot 스택의 top에는 a 스택의 top 값이 있음.
		if (ft_deque_front_pop(&pivot, &pivot_a) == -1)
			return (-1);
		// pivot의 top 밑의 값은 b에 pivot 값으로 저장되어있음.
		// b 스택 pivot
		// 만약 b에 pivot값이 없으면 바닥에 있는 원소를 pivot_b로 지정
		if (pivot == NULL)
		{
			if (ft_deque_front_peak(&stack_b, &pivot_b) == -1)
				return (-1);
		}
		else
		{
			// pivot이 있으면 pivot 위에 있는 값을 새 pivot으로 지정함
			if (ft_deque_front_peak(&pivot, &pivot_b) == -1)
				return (-1);
			ft_lstprevval(stack_b, pivot_b, &pivot_b);
		}
		// b pivot 수행
		tmp = ft_b_stack_pivot(&stack_a, &stack_b, ft_lstdist(stack_b, pivot_b), pivot_b);
		// b pivot에선 pivot보다 작은 것들을 밑으로 보내는데 어차피 Pivot보다 작으므로 다시 돌릴 필요 없지 않나?
		//ft_cmd_n(&stack_a, &stack_b, "rrb", tmp);

		// b pivot을 하며 pivot보다 큰 값을 a로 보냈는데
		// a가 정렬되어 있지 않으면 기존 a pivot ~ top까지 정렬 혹은 pivot 해야 함.
		// 일단 정렬되어 있는지 확인해 본다.
		if (ft_lstissort(stack_a) == -1)
		{
			// 정렬이 되어있지 않으면 먼저 top부터 pivot 까지의 depth를 확인해 본다.
			tmp = ft_lstdist(stack_a, pivot_a);
			// 만약에 depth가 2 이하라면
			if (tmp < 3)
			{
				if (ft_check_ps_none(&stack_a, pivot_a) == 0)
				{
					printf("case 1\n");
					ft_cmd_n(&stack_a, &stack_b, "pa", 1);
					if (ft_deque_back_peak(&stack_a, &tmp) == -1)
						return (-1);
					ft_deque_front_push(&pivot, tmp);
				}
				else if (ft_check_ps_one(&stack_a, pivot_a) == 0)
					printf("case 2\n");
				else if (ft_check_ps_two(&stack_a, pivot_a) == 0)
					printf("case 3\n");
				else
					printf("case 4\n");
			}
			else
			{
				// depth가 3 이상이면 pivot을 또 나눔
				//printf("pivot\n");
				ft_lstprevval(stack_a, pivot_a, &pivot_a);
				tmp = ft_a_stack_pivot(&stack_a, &stack_b, ft_lstdist(stack_a, pivot_a), pivot_a);
				ft_cmd_n(&stack_a, &stack_b, "rra", tmp);
				ft_deque_front_push(&pivot, pivot_a);
			}
			

		}
		else
		{
			// 정렬되어 있으면 a 위에 있는 값을 새 pivot으로 지정함
			if (ft_deque_back_peak(&stack_a, &tmp) == -1)
				return (-1);
			ft_deque_front_push(&pivot, tmp);
		}
		
		// 다시 a 스택에 대해 a에 있는 Pivot 까지만 pivot 함
		// a 스택은 정렬된 상태를 유지해야 하므로 정렬될 때 까지 다시 a에 대해 pivot함.
		// a의 Pivot 부터 바닥까지는 정렬되어 있어야 함. 그래서 pivot부터 top까지 정렬되어 있지 않다면 정렬될 때 까지 Pivot 작업을 해야 한다.
		// 


		// 이 때 a 스택에 있는 이전 pivot은 지워도 됨. 왜냐면 스택 바닥부터 pivot은 정렬됨.
		/*
		ft_lstprevval(stack_a, pivot_a, &pivot_a);
		ft_deque_front_push(&pivot, pivot_a);
		tmp = ft_a_stack_pivot(&stack_a, &stack_b, ft_lstdist(stack_a, pivot_a), pivot_a);
		ft_cmd_n(&stack_a, &stack_b, "rra", tmp);
		*/
		i++;
		if (i > 1)
			break ;
	}
/*
	ft_deque_front_peak(&stack_b, &tmp);
	ft_b_stack_pivot(&stack_a, &stack_b, ft_lstdist(stack_b, tmp), tmp);
	ft_deque_front_push(&pivot_in_b, tmp);


	ft_deque_front_peak(&pivot_in_a, &tmp);
	ft_lstprevval(stack_a, tmp, &tmp);
	//printf("tmp : %d\n", tmp);
	tmp = ft_a_stack_pivot(&stack_a, &stack_b, ft_lstdist(stack_a, tmp), tmp);
	ft_cmd_n(&stack_a, &stack_b, "rra", tmp);

	while (ft_deque_front_pop(&pivot_in_a, &tmp) == 0)
		printf("pivot in a : %d\n", tmp);

	while (ft_deque_front_pop(&pivot_in_b, &tmp) == 0)
		printf("pivot in b : %d\n", tmp);
	test_bstack_pre(&stack_a, &stack_b, &pivot_in_a);
*/
	/*
	while (ft_lstissort(stack_a) == -1)
		printf("rotate : %d\n", test_first_pivot(&stack_a, &stack_b, &pivot));
	//test_bstack_pre(&stack_a, &stack_b, &pivot);

	while (ft_deque_front_pop(&pivot, &tmp) == 0)
		printf("len : %d\n", ft_lstdist(stack_b, tmp));

	*/

	return (0);
}
