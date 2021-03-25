/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacka_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:16:40 by joopark           #+#    #+#             */
/*   Updated: 2021/03/25 20:32:00 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int	ft_stacka_proc(t_list **sa, t_list **sb, t_list **p, int *h)
{
	int	pivot;
	int	len;
	int	tmp;

	len = ft_lstdist(*sa, *h);
	if (len < 3 || (ft_lstissort_len(*sa, len) == 0))
	{
		if (len == 1)
			ft_stacka_head_swap(sa, sb);
		else if (len == 2)
			ft_stacka_three_swap(sa, sb);
		ft_deque_front_peak(sa, h);
	}
	else
	{
		if (ft_get_center(*sa, len, &pivot) != 0)
			return (-1);
		tmp = ft_a_stack_pivot(sa, sb, len, pivot);
		ft_cmd_n(sa, sb, "rra", tmp);
		ft_deque_front_peak(sb, &pivot);
		ft_deque_front_push(p, pivot);
	}
	return (0);
}

int	ft_first_pivot(t_list **sa, t_list **sb, t_list **p)
{
	int	pivot;
	int	len;

	len = ft_lstsize(*sa);
	if (len < 4 || (ft_lstissort_len(*sa, len) == 0))
	{
		if (len == 2)
			ft_stacka_head_swap(sa, sb);
		else if (len == 3)
			ft_stacka_three_swap(sa, sb);
	}
	else
	{
		if (ft_get_center(*sa, len, &pivot) != 0)
			return (-1);
		ft_a_stack_pivot(sa, sb, len, pivot);
		ft_deque_front_push(p, pivot);
	}
	return (0);
}

int	ft_stacka_head_swap(t_list **stack_a, t_list **stack_b)
{
	int	top;
	int	bottom;

	if (ft_lstsize(*stack_a) < 2)
		return (0);
	if (ft_deque_front_pop(stack_a, &top) == -1)
		return (-1);
	if (ft_deque_front_peak(stack_a, &bottom) == -1)
		return (-1);
	if (ft_deque_front_push(stack_a, top) == -1)
		return (-1);
	if (bottom < top)
		ft_cmd_n(stack_a, stack_b, "sa", 1);
	return (0);
}

int	ft_stacka_three_swap(t_list **stack_a, t_list **stack_b)
{
	int	*elem;

	elem = ft_get_elem(*stack_a, 3);
	if (elem == NULL)
		return (-1);
	if (elem[0] > elem[1])
		ft_cmd_n(stack_a, stack_b, "sa", 1);
	if (ft_lstsize(*stack_a) <= 3)
	{
		if (elem[2] < elem[0] || elem[2] < elem[1])
			ft_cmd_n(stack_a, stack_b, "rra", 1);
		ft_stacka_head_swap(stack_a, stack_b);
	}
	else
	{
		if (elem[2] < elem[0] || elem[2] < elem[1])
			ft_cmd_n(stack_a, stack_b, "pb", 1);
		ft_stacka_head_swap(stack_a, stack_b);
		if (elem[2] < elem[0] || elem[2] < elem[1])
			ft_cmd_n(stack_a, stack_b, "pa", 1);
		ft_stacka_head_swap(stack_a, stack_b);
	}
	free(elem);
	return (0);
}
