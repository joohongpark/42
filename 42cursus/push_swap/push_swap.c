/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:20:02 by joopark           #+#    #+#             */
/*   Updated: 2021/03/10 20:12:43 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>
#include <stdio.h>

int				main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t_list		*deque;
	int			val;

	deque = NULL;
	for (int i = 0; i < 30; i++)
	{
		if (ft_deque_back_push(&deque, i) == 0)
			printf("ok\n");
	}
	while (ft_deque_front_pop(&deque, &val) == 0)
	{
		printf("val : %d\n", val);
	}
	return (0);
}
