/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:20:02 by joopark           #+#    #+#             */
/*   Updated: 2021/03/25 23:51:24 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>
#include <stdio.h>

int				main(int argc, char *argv[])
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*pivot;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	pivot = NULL;
	i = 0;
	if (argc < 2)
		return (0);
	ft_insert_stack(&stack_a, argc, argv);
	while (ft_lstissort(stack_a) == -1)
		ft_first_pivot(&stack_a, &stack_b, &pivot);
	ft_stack_sort(&stack_a, &stack_b, &pivot);
	ft_cmd_n(NULL, NULL, NULL, -1);
	return (0);
}
