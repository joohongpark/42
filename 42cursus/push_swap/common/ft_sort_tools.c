/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:22:48 by joopark           #+#    #+#             */
/*   Updated: 2021/03/23 02:34:48 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int	ft_a_stack_pivot(t_list **sa, t_list **sb, int n, int pivot)
{
	int	rtn;
	int	tmp;
	int	p;

	rtn = 0;
	p = 0;
	while (n > 0)
	{
		if (ft_deque_front_peak(sa, &tmp) == -1)
			return (-1);
		if (pivot < tmp)
			rtn += ft_cmd_n(sa, sb, "ra", 1);
		else
			ft_cmd_n(sa, sb, "pb", 1);
		if (pivot == tmp && ft_lstsize(*sb) > 1)
			p = ft_cmd_n(sa, sb, "rb", 1);
		n--;
	}
	if (p == 1)
		ft_cmd_n(sa, sb, "rrb", 1);
	return (rtn);
}

int	ft_b_stack_pivot(t_list **sa, t_list **sb, int n, int pivot)
{
	int	rtn;
	int	tmp;
	int	p;

	rtn = 0;
	p = 0;
	while (n > 0)
	{
		if (ft_deque_front_peak(sb, &tmp) == -1)
			return (-1);
		if (pivot > tmp)
			rtn += ft_cmd_n(sa, sb, "rb", 1);
		else
			ft_cmd_n(sa, sb, "pa", 1);
		if (pivot == tmp && ft_lstsize(*sa) > 1)
			p = ft_cmd_n(sa, sb, "ra", 1);
		n--;
	}
	if (p == 1)
		ft_cmd_n(sa, sb, "rra", 1);
	return (rtn);
}

int	ft_cmd_n(t_list **sa, t_list **sb, char *cmd, int n)
{
	while (n > 0)
	{
		ft_op(sa, sb, cmd);
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
		n--;
	}
	return (1);
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
