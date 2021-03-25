/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackb_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:17:47 by joopark           #+#    #+#             */
/*   Updated: 2021/03/25 20:50:24 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int	ft_stackb_pivot(t_list **sa, t_list **sb, t_list **p)
{
	int pivot;
	int	pivot_dist;
	int	rev;
	int	tmp;

	ft_deque_front_pop(p, &pivot);
	pivot_dist = ft_lstdist(*sb, pivot);
	if (pivot_dist == 1)
		ft_stackb_head_swap(sa, sb);
	if (pivot_dist == 2)
		ft_stackb_three_swap(sa, sb);
	if ((pivot_dist < 3) || ft_lstisrevsort_len(*sb, pivot_dist + 1) == 0)
		ft_cmd_n(sa, sb, "pa", pivot_dist + 1);
	else 
	{
		if (ft_get_center(*sb, pivot_dist, &pivot) != 0)
			return (-1);
		rev = ft_b_stack_pivot(sa, sb, pivot_dist, pivot);
		ft_deque_front_peak(sb, &tmp);
		ft_deque_front_push(p, tmp);
		ft_cmd_n(sa, sb, "rrb", rev);
		ft_cmd_n(sa, sb, "pb", 1);
		ft_deque_front_push(p, pivot);
	}
	return (0);
}

int	ft_stackb_pivot_tail(t_list **sa, t_list **sb, t_list **p)
{
	int	pivot;
	int	stack_len;

	stack_len = ft_lstsize(*sb);
	if (stack_len == 2)
		ft_stackb_head_swap(sa, sb);
	if (stack_len == 3)
		ft_stackb_three_swap(sa, sb);
	if (stack_len > 0 && stack_len < 4)
		ft_cmd_n(sa, sb, "pa", stack_len);
	else 
	{
		if (ft_get_center(*sb, stack_len, &pivot) != 0)
			return (-1);
		ft_b_stack_pivot(sa, sb, stack_len, pivot);
		ft_cmd_n(sa, sb, "pb", 1);
		if (ft_deque_front_push(p, pivot) == -1)
			return (-1);
	}
	return (0);
}

int	ft_stackb_head_swap(t_list **stack_a, t_list **stack_b)
{
	int	top;
	int	bottom;

	if (ft_lstsize(*stack_b) < 2)
		return (0);
	if (ft_deque_front_pop(stack_b, &top) == -1)
		return (-1);
	if (ft_deque_front_peak(stack_b, &bottom) == -1)
		return (-1);
	if (ft_deque_front_push(stack_b, top) == -1)
		return (-1);
	if (bottom > top)
		ft_cmd_n(stack_a, stack_b, "sb", 1);
	return (0);
}

int	ft_stackb_three_swap(t_list **stack_a, t_list **stack_b)
{
	int	*elem;

	elem = ft_get_elem(*stack_b, 3);
	if (elem == NULL)
		return (-1);
	if (elem[0] < elem[1])
		ft_cmd_n(stack_a, stack_b, "sb", 1);
	if (ft_lstsize(*stack_a) <= 3)
	{
		if (elem[2] > elem[0] || elem[2] > elem[1])
			ft_cmd_n(stack_a, stack_b, "rrb", 1);
		ft_stackb_head_swap(stack_a, stack_b);
	}
	else
	{
		if (elem[2] > elem[0] || elem[2] > elem[1])
			ft_cmd_n(stack_a, stack_b, "pa", 1);
		ft_stackb_head_swap(stack_a, stack_b);
		if (elem[2] > elem[0] || elem[2] > elem[1])
			ft_cmd_n(stack_a, stack_b, "pb", 1);
		ft_stackb_head_swap(stack_a, stack_b);
	}
	free(elem);
	return (0);
}
