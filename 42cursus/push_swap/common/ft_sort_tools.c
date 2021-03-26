/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:22:48 by joopark           #+#    #+#             */
/*   Updated: 2021/03/26 03:03:57 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int	ft_stack_sort(t_list **stack_a, t_list **stack_b, t_list **pivot)
{
	int			stack_a_head;
	int			pivot_a_pos;

	if (ft_deque_front_peak(stack_a, &stack_a_head) == -1)
		return (-1);
	while (1)
	{
		pivot_a_pos = ft_lstdist(*stack_a, stack_a_head);
		if (pivot_a_pos == 0 && *stack_b == NULL)
			break ;
		else if (pivot_a_pos != 0)
			ft_stacka_proc(stack_a, stack_b, pivot, &stack_a_head);
		else
		{
			if (*stack_b == NULL)
				break ;
			if (*pivot == NULL)
				ft_stackb_pivot_tail(stack_a, stack_b, pivot);
			else
				ft_stackb_pivot(stack_a, stack_b, pivot);
		}
	}
	return (0);
}

int	ft_get_center(t_list *stack, int depth, int *val)
{
	int	*list;

	list = ft_get_elem(stack, depth);
	if (list == NULL)
		return (-1);
	ft_quicksort(list, 0, depth - 1);
	if (depth < 5)
		depth = depth / 2 - 1;
	else
		depth = depth / 2;
	*val = list[depth];
	free(list);
	return (0);
}

int	ft_a_stack_pivot(t_list **sa, t_list **sb, int n, int pivot)
{
	int	rtn;
	int	tmp;
	int	p;
	int	i;

	rtn = 0;
	p = 0;
	i = 0;
	while (i != n)
	{
		if (ft_deque_front_peak(sa, &tmp) == -1)
			return (-1);
		if (pivot < tmp && ft_lstsize(*sa) > 1)
			rtn += ft_cmd_n(sa, sb, "ra", 1);
		else
			ft_cmd_n(sa, sb, "pb", 1);
		if (pivot == tmp && (i + 1) != n)
			p = 1;
		if (pivot == tmp && ft_lstsize(*sb) > 1 && (i + 1) != n)
			p = ft_cmd_n(sa, sb, "rb", 1);
		i++;
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
	int	i;

	rtn = 0;
	p = 0;
	i = 0;
	while (i != n)
	{
		if (ft_deque_front_peak(sb, &tmp) == -1)
			return (-1);
		if (pivot > tmp && ft_lstsize(*sb) > 1)
			rtn += ft_cmd_n(sa, sb, "rb", 1);
		else
			ft_cmd_n(sa, sb, "pa", 1);
		if (pivot == tmp && (i + 1) != n)
			p = 1;
		if (pivot == tmp && ft_lstsize(*sa) > 1 && (i + 1) != n)
			p = ft_cmd_n(sa, sb, "ra", 1);
		i++;
	}
	if (p == 1)
		ft_cmd_n(sa, sb, "rra", 1);
	return (rtn);
}

int	ft_cmd_n(t_list **sa, t_list **sb, char *cmd, int n)
{
	static char	*string = NULL;

	while (n > 0)
	{
		ft_op(sa, sb, cmd);
		string = ft_strnstack(string, cmd, ft_strlen(cmd));
		string = ft_strnstack(string, "\n", 1);
		n--;
	}
	if (n == -1 && string != NULL)
	{
		string = ft_strreplace(string, "\nra\nrb\n", "\nrr\n");
		string = ft_strreplace(string, "\nrra\nrrb\n", "\nrrr\n");
		string = ft_strreplace(string, "\nrb\nra\n", "\nrr\n");
		string = ft_strreplace(string, "\nrrb\nrra\n", "\nrrr\n");
		string = ft_strreplace(string, "\nrr\nrrr\n", "\n");
		string = ft_strreplace(string, "\nrrr\nrr\n", "\n");
		write(1, string, ft_strlen(string));
		free(string);
	}
	return (1);
}
