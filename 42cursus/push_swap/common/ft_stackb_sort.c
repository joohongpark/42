/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackb_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:17:47 by joopark           #+#    #+#             */
/*   Updated: 2021/03/23 17:17:51 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

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
