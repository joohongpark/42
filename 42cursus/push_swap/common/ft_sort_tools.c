/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:22:48 by joopark           #+#    #+#             */
/*   Updated: 2021/03/23 16:43:00 by joopark          ###   ########.fr       */
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
