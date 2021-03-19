/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:22:48 by joopark           #+#    #+#             */
/*   Updated: 2021/03/18 13:50:53 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int	ft_a_stack_pivot(t_list **sa, t_list **sb, int n, int pivot)
{
	int	rtn;
	int	tmp;

	rtn = 0;
	while (n > 0)
	{
		if (ft_deque_front_peak(sa, &tmp) == -1)
			return (-1);
		if (pivot == tmp)
			break ;
		if (pivot < tmp)
		{
			ft_op(sa, sb, "ra");
			write(1, "ra\n", 3);
			rtn++;
		}
		else
		{
			ft_op(sa, sb, "pb");
			write(1, "pb\n", 3);
		}
		n--;
	}
	return (rtn);
}

int	ft_b_stack_pivot(t_list **sa, t_list **sb, int n, int pivot)
{
	int	rtn;
	int	tmp;

	rtn = 0;
	while (n > 0)
	{
		if (ft_deque_front_peak(sb, &tmp) == -1)
			return (-1);
		if (pivot == tmp)
			break ;
		if (pivot > tmp)
		{
			ft_op(sa, sb, "rb");
			write(1, "rb\n", 3);
			rtn++;
		}
		else
		{
			ft_op(sa, sb, "pa");
			write(1, "pa\n", 3);
		}
		n--;
	}
	return (rtn);
}

void	ft_cmd_n(t_list **sa, t_list **sb, char *cmd, int n)
{
	while (n > 0)
	{
		ft_op(sa, sb, cmd);
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
		n--;
	}
}
