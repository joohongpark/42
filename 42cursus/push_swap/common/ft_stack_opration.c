/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_opration.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:26:36 by joopark           #+#    #+#             */
/*   Updated: 2021/03/10 23:53:57 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int				ft_op(t_list **stack_a, t_list **stack_b, char *op)
{
	if (ft_strncmp(op, "sa", 3) == 0)
		return (ft_swap(stack_a));
	else if (ft_strncmp(op, "sb", 3) == 0)
		return (ft_swap(stack_b));
	else if (ft_strncmp(op, "ss", 3) == 0)
		return (ft_swap(stack_a) + ft_swap(stack_b));
	else if (ft_strncmp(op, "pa", 3) == 0)
		return (ft_push(stack_a, stack_b));
	else if (ft_strncmp(op, "pb", 3) == 0)
		return (ft_push(stack_b, stack_a));
	else if (ft_strncmp(op, "ra", 3) == 0)
		return (ft_rotate(stack_a));
	else if (ft_strncmp(op, "rb", 3) == 0)
		return (ft_rotate(stack_b));
	else if (ft_strncmp(op, "rr", 3) == 0)
		return (ft_rotate(stack_a) + ft_rotate(stack_b));
	else if (ft_strncmp(op, "rra", 4) == 0)
		return (ft_reverse_rotate(stack_a));
	else if (ft_strncmp(op, "rrb", 4) == 0)
		return (ft_reverse_rotate(stack_b));
	else if (ft_strncmp(op, "rrr", 4) == 0)
		return (ft_reverse_rotate(stack_a) + ft_reverse_rotate(stack_b));
	else
		return (1);
}

int				ft_swap(t_list **stack)
{
	int			first;
	int			second;
	int			first_val;
	int			second_val;
	int			rtn;

	first = ft_deque_front_pop(stack, &first_val);
	second = ft_deque_front_pop(stack, &second_val);
	if (first == 0 && second == 0)
	{
		rtn = ft_deque_front_push(stack, first_val);
		rtn += ft_deque_front_push(stack, second_val);
	}
	else if (first == 0 && second == -1)
		rtn = ft_deque_front_push(stack, first_val);
	else
		rtn = 0;
	return (rtn);
}

int				ft_push(t_list **stacka, t_list **stackb)
{
	int			val;
	int			status;

	status = ft_deque_front_pop(stackb, &val);
	if (status == -1)
		return (0);
	status = ft_deque_front_push(stacka, val);
	return (status);
}

int				ft_rotate(t_list **stack)
{
	int			val;
	int			status;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	status = ft_deque_front_pop(stack, &val);
	status = ft_deque_back_push(stack, val);
	return (status);
}

int				ft_reverse_rotate(t_list **stack)
{
	int			val;
	int			status;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	status = ft_deque_back_pop(stack, &val);
	status = ft_deque_front_push(stack, val);
	return (status);
}
