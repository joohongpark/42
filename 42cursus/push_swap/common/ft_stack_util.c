/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:26:35 by joopark           #+#    #+#             */
/*   Updated: 2021/03/15 15:27:43 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

void	ft_insert_stack(t_list **stack_a, int argc, char *argv[])
{
	int			i;
	int			val;

	i = 1;
	while (i < argc)
	{
		if (ft_str_is_int(argv[i]) == -1
			|| ft_atoi(argv[i], &val) == -1
			|| ft_lstdupchk(*stack_a, val) == -1
			|| ft_deque_back_push(stack_a, val) != 0)
		{
			ft_err_exit(stack_a, stack_a);
		}
		i++;
	}
}

void	ft_err_exit(t_list **stack_a, t_list **stack_b)
{
	int	dummy;

	while (ft_deque_front_pop(stack_a, &dummy) == 0)
		;
	while (ft_deque_front_pop(stack_b, &dummy) == 0)
		;
	write(2, "Error\n", 6);
	exit(0);
}
