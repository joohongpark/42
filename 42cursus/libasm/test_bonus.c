/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:21:08 by joopark           #+#    #+#             */
/*   Updated: 2021/01/20 01:58:33 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libasm_bonus.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>

void		ft_atoi_base_test(void);

int main (void)
{
	ft_atoi_base_test();
	return (0);
}

void		ft_atoi_base_test(void)
{
	printf("%d\n", ft_atoi_base("x 1234", "0123456789"));
	printf("%d\n", ft_atoi_base("4321s", "0123456789"));
	printf("%d\n", ft_atoi_base("-123456789", "0123456789"));
	printf("%d\n", ft_atoi_base("+2147483647", "0123456789"));
	printf("%d\n", ft_atoi_base("-2147483648", "0123456789"));
	printf("%d\n", ft_atoi_base("     7fffffff", "0123456789abcdef"));
}
