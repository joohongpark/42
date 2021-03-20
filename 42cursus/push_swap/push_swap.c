/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:20:02 by joopark           #+#    #+#             */
/*   Updated: 2021/03/20 19:39:34 by joopark          ###   ########.fr       */
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

	if (ft_deque_back_peak(stack_a, &pivot) == -1)
		return (-1);
	ft_deque_front_push(t_pivot, pivot);
	return (ft_a_stack_pivot(stack_a, stack_b, ft_lstsize(*stack_a) - 1, pivot));
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
	t_list		*pivot_between_ab;
	int			tmp;
	int			tmp1;
	int			rtn;
	int			pivot_a;
	int			pivot_a_pos;
	int			pivot_b;
	int			i;
	int			debug = 0;

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
	// 1. stack a 에 대해 정렬될때까지 pivot 나누기 수행
	while (ft_lstissort(stack_a) == -1)
		test_first_pivot(&stack_a, &stack_b, &pivot);
	// 2. pivot 사이에 원소들이 정렬될 때 까지 (pivot 사이 원소들이 정렬되면 Pivot 원소를 pop함.)
	while (pivot != NULL || pivot_between_ab != NULL)
	{
		if (debug == 1)
		{
			write(1, "==========", 10);
			write(1, "[", 1);
			ft_putnbr_fd(i, 1);
			write(1, "]", 1);
			write(1, "=========\n", 10);
		}

		// 1. pivot 스택의 top을 뽑아놓는다. (a 스택에 포함되어 있어야 함.)
		if (ft_deque_front_pop(&pivot, &pivot_a) == -1)
			return (-1);

		// 2. pivot 스택의 top이 a 스택에 어느 위치에 있는지 확인한다.
		pivot_a_pos = ft_lstdist(stack_a, pivot_a);
		
		// 2-1. 만약 pivot 스택의 top이 a 스택에 존재하지 않으면? -> 이런 경우는 발생해서는 안된다.
		if (pivot_a_pos == -1)
		{
			write(1, "error (pivot_a_pos == -1)\n", 26);
			return (0);
		}
		// 2-2. 만약 pivot 스택의 top이 a 스택의 top이라면? -> 이런 경우 a는 정렬되어 있으므로 b 스택에 접근한다.
		else if (pivot_a_pos == 0)
		{
			if (debug == 1)
				write(1, "pivot_a_pos == 0\n", 17);
			// 2-2-1. 만약 정렬되어 있지 않으면? -> 이 경우도 발생해선 안된다.
			if (ft_lstissort(stack_a) == -1)
			{
				write(1, "error (2-2-1)\n", 14);
				return (0);
			}
			// 2-2-2. b 스택에 접근하여 b 스택에 pivot을 수행한다.
			else
			{
				// 2-2-2-1. b 스택도 역정렬 되어 있으면 다 몰아넣고 루프를 끝낸다.
				if (ft_lstisrevsort(stack_b) == 0)
				{
					tmp = ft_lstsize(stack_b);
					ft_cmd_n(&stack_a, &stack_b, "pa", tmp);
					break ;
				}
				// 2-2-2-2-1. b 스택에 대해 pivot할 pivot 값을 정한다.
				// 2-2-2-2-1-1. 만약 b 스택 내 pivot도 존재하지 않고, a와 b 스택 사이 pivot도 존재하지 않으면 b 스택의 바닥 값을 새 pivot으로 삼는다.
				if (pivot == NULL && pivot_between_ab == NULL)
				{
					if (debug == 1)
						write(1, "2-2-2-2-1-1\n", 12);
					if (ft_deque_back_peak(&stack_b, &pivot_b) == -1)
						return (-1);
					// b 스택을 pivot 기준으로 나누고 a와 b 스택 사이 pivot에 이 값을 추가한다.
					if (debug == 1)
					{
						write(1, "[", 1);
						ft_putnbr_fd(pivot_b, 1);
						write(1, "]\n", 2);
					}
					tmp1 = ft_lstdist(stack_b, pivot_b);
					tmp = ft_b_stack_pivot(&stack_a, &stack_b, ft_lstdist(stack_b, pivot_b), pivot_b);
					// b pivot에선 pivot보다 작은 것들을 밑으로 보내는데 어차피 Pivot보다 작으므로 다시 돌릴 필요 없지 않나?
					//ft_cmd_n(&stack_a, &stack_b, "rrb", tmp);
					if (tmp1 != 0)
					{
						if (ft_deque_front_push(&pivot_between_ab, pivot_b) == -1)
							return (-1);
					}
				}
				// 2-2-2-2-1-2. b 스택 내 pivot 존재여부와 상관없이 a와 b 스택 사이 pivot이 존재하면 스택 위의 이 값을 pivot으로 삼는다.
				else if (pivot_between_ab != NULL)
				{
					if (debug == 1)
						write(1, "2-2-2-2-1-2\n", 12);
					if (ft_deque_front_peak(&pivot_between_ab, &pivot_b) == -1)
						return (-1);
					// 만약에 이 pivot 값이 top이라면 a와 b 스택 사이 pivot에서 이 값을 뽑고 pa 연산을 수행한다.
					if (ft_lstdist(stack_b, pivot_b) == 0)
					{
						if (debug == 1)
							write(1, "2-2-2-2-1-2-1\n", 14);
						if (ft_deque_front_pop(&pivot_between_ab, &pivot_b) == -1)
							return (-1);
						ft_cmd_n(&stack_a, &stack_b, "pa", 1);
					}
					// top가 아니라면 이 위의 값을 pivot으로 삼고 b 스택을 pivot 기준으로 나누고 a와 b 스택 사이 pivot에 이 값을 추가한다.
					else
					{
						if (debug == 1)
							write(1, "2-2-2-2-1-2-2\n", 14);
						// 만약에 이 pivot 값이 top이라면 pivot 값을 뽑는다.
						if (ft_lstoverval(stack_b, pivot_b, &pivot_b) == 0)
						{
							if (ft_deque_front_pop(&pivot_between_ab, &pivot_b) == -1)
								return (-1);
						}
						if (debug == 1)
						{
							write(1, "[", 1);
							ft_putnbr_fd(pivot_b, 1);
							write(1, "]\n", 2);
						}
						tmp1 = ft_lstdist(stack_b, pivot_b);
						tmp = ft_b_stack_pivot(&stack_a, &stack_b, ft_lstdist(stack_b, pivot_b), pivot_b);
						// b pivot에선 pivot보다 작은 것들을 밑으로 보내는데 어차피 Pivot보다 작으므로 다시 돌릴 필요 없지 않나?
						//ft_cmd_n(&stack_a, &stack_b, "rrb", tmp);
						if (tmp1 != 0)
						{
							if (ft_deque_front_push(&pivot_between_ab, pivot_b) == -1)
								return (-1);
						}
					}
				}
				// 2-2-2-2-1-3. a와 b 스택 사이 pivot이 존재하지 않으면 pivot 목록에서 pivot을 뽑아온다.
				else
				{
					if (debug == 1)
						write(1, "2-2-2-2-1-3\n", 12);
					if (ft_deque_front_peak(&pivot, &pivot_b) == -1)
						return (-1);
					// 만약에 이 pivot 값이 top이라면 pivot 목록에서 이 값을 뽑고 pa 연산을 수행한다.
					if (ft_lstdist(stack_b, pivot_b) == 0)
					{
						if (debug == 1)
							write(1, "2-2-2-2-1-3-1\n", 14);
						if (ft_deque_front_pop(&pivot, &pivot_b) == -1)
							return (-1);
						ft_cmd_n(&stack_a, &stack_b, "pa", 1);
					}
					// top가 아니라면 이 위의 값을 pivot으로 삼고 b 스택을 pivot 기준으로 나누고 a와 b 스택 사이 pivot에 이 값을 추가한다.
					else
					{
						if (debug == 1)
							write(1, "2-2-2-2-1-3-2\n", 14);
						// 만약에 이 pivot 값이 top이라면 pivot 값을 뽑는다.
						if (ft_lstoverval(stack_b, pivot_b, &pivot_b) == 0)
						{
							if (ft_deque_front_pop(&pivot, &pivot_b) == -1)
								return (-1);
						}
						tmp1 = ft_lstdist(stack_b, pivot_b);
						if (debug == 1)
						{
							write(1, "[", 1);
							ft_putnbr_fd(pivot_b, 1);
							write(1, "]\n", 2);
						}
						tmp = ft_b_stack_pivot(&stack_a, &stack_b, ft_lstdist(stack_b, pivot_b), pivot_b);
						// b pivot에선 pivot보다 작은 것들을 밑으로 보내는데 어차피 Pivot보다 작으므로 다시 돌릴 필요 없지 않나?
						//ft_cmd_n(&stack_a, &stack_b, "rrb", tmp);
						if (tmp1 != 0)
						{
							if (ft_deque_front_push(&pivot_between_ab, pivot_b) == -1)
								return (-1);
						}
					}
				}
			}
		}
		// 2-3. 만약 pivot 스택의 top이 a 스택의 top의 바로 밑 값이라면 -> 여기서 pivot은 무조건 top보다 원소 하나만큼 큼
		else if (pivot_a_pos == 1)
		{
			if (debug == 1)
				write(1, "pivot_a_pos == 1\n", 17);
			// 이부분 효율적으로 수정해야함. top이 더 크면 swap하는 구문임.
			if (ft_deque_front_pop(&stack_a, &tmp) == -1)
				return (-1);
			if (ft_deque_front_peak(&stack_a, &tmp1) == -1)
				return (-1);
			if (ft_deque_front_push(&stack_a, tmp) == -1)
				return (-1);
			if (tmp > tmp1)
				ft_cmd_n(&stack_a, &stack_b, "sa", 1);
			if (ft_deque_front_peak(&stack_a, &pivot_a) == -1)
				return (-1);
		}
		// 2-4. 만약 pivot 스택의 top이 a 스택의 top과 차이가 2 이상 난다면 -> a 스택 pivot
		else
		{
			if (debug == 1)
				write(1, "pivot_a_pos > 1\n", 16);
			if (ft_lstoverval(stack_a, pivot_a, &tmp) == -1)
			{
				printf("error (?)\n");
				break ;
			}
			tmp1 = ft_lstdist(stack_a, tmp);
			tmp = ft_a_stack_pivot(&stack_a, &stack_b, tmp1, tmp);
			if (tmp1 > 0)
			{
				ft_cmd_n(&stack_a, &stack_b, "pb", 1);
			}
			ft_cmd_n(&stack_a, &stack_b, "rra", tmp);
			// a 스택과 b 스택 사이에 있는 피봇 추가
			if (ft_deque_front_peak(&stack_b, &pivot_b) == -1)
				return (-1);
			if (debug == 1)
			{
				write(1, "[", 1);
				ft_putnbr_fd(pivot_b, 1);
				write(1, "]\n", 2);
			}
			ft_deque_front_push(&pivot_between_ab, pivot_b);
		}
		ft_deque_front_push(&pivot, pivot_a);
		i++;
		if (i > 15430)
		{
			if (debug == 1)
			{
				printf("error (%d, stack a top : %d, pivot : %d, stack a size : %d)\n", tmp, i, pivot_a, ft_lstsize(stack_a));
				__dump("stack_a", &stack_a);
				__dump("stack_b", &stack_b);
				__dump("pivot", &pivot);
				__dump("pivot_between_ab", &pivot_between_ab);
			}
			break ;
		}
	}

	return (0);
}
