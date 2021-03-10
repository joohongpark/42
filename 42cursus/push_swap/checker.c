/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:19:50 by joopark           #+#    #+#             */
/*   Updated: 2021/03/10 23:52:43 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>
#include <stdio.h>

int				main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int			val;
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	for (int i = 0; i < 10; i++)
	{
		if (ft_deque_back_push(&stack_a, i) == 0)
			printf("ok\n");
	}
	for (int i = 0; i < 5; i++)
	{
		if (ft_op(&stack_a, &stack_b, "rrr") == 0)
			printf("[op] ok\n");
	}
	while (ft_deque_front_pop(&stack_a, &val) == 0)
	{
		printf("val : %d\n", val);
	}
	return (0);
}
