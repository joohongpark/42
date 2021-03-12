/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:19:50 by joopark           #+#    #+#             */
/*   Updated: 2021/03/11 21:11:56 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

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

void	ft_exe_op(t_list **stack_a, t_list **stack_b)
{
	char		*bp;
	char		*line;
	int			gnl;

	bp = NULL;
	while (1)
	{
		line = NULL;
		gnl = ft_get_next_line(0, &line, &bp);
		if (gnl < 1)
			break ;
		if (ft_op(stack_a, stack_b, line) == 1)
		{
			if (line != NULL)
				free(line);
			ft_err_exit(stack_a, stack_b);
		}
		if (line != NULL)
			free(line);
	}
}

int	main(int argc, char *argv[])
{
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	ft_insert_stack(&stack_a, argc, argv);
	ft_exe_op(&stack_a, &stack_b);
	if (stack_b != NULL || ft_lstissort(stack_a) == -1)
		write(2, "KO\n", 3);
	else
		write(2, "OK\n", 3);
	return (0);
}
