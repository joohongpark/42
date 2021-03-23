/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackb_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:17:47 by joopark           #+#    #+#             */
/*   Updated: 2021/03/23 21:03:50 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

void	ft_stackb_rev(t_list **stack_a, t_list **stack_b, int len)
{
	if (len > 0)
	{
		ft_cmd_n(stack_a, stack_b, "pa", len);
		ft_cmd_n(stack_a, stack_b, "ra", len - 1);
	}
	while (len > 0)
	{
		ft_cmd_n(stack_a, stack_b, "pb", 1);
		if (len != 1)
			ft_cmd_n(stack_a, stack_b, "rra", 1);
		len--;
	}
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
