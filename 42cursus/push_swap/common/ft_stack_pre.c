/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:12:54 by joopark           #+#    #+#             */
/*   Updated: 2021/03/23 17:30:13 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

void	ft_stack_pre(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (ft_lstisrevsort(*stack_a) == 0 && ft_lstsize(*stack_a) > 3)
		ft_stacka_rev(stack_a, stack_b, size);
}
