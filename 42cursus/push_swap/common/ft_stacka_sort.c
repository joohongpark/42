/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacka_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:16:40 by joopark           #+#    #+#             */
/*   Updated: 2021/03/23 17:24:35 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

void	ft_stacka_rev(t_list **stack_a, t_list **stack_b, int len)
{
	if (len > 0)
		ft_cmd_n(stack_a, stack_b, "pb", len);
	while (len > 0)
	{
		if (len != 1)
			ft_cmd_n(stack_a, stack_b, "rrb", 1);
		ft_cmd_n(stack_a, stack_b, "pa", 1);
		len--;
	}
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
