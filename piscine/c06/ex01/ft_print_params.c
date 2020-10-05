/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:20:32 by joopark           #+#    #+#             */
/*   Updated: 2020/08/10 16:22:28 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			main(int argc, char *argv[])
{
	int		len;
	int		idx;

	idx = argc;
	while (--idx > 0)
	{
		len = 0;
		while (argv[argc - idx][len] != 0)
			len++;
		write(1, argv[argc - idx], len);
		write(1, "\n", 1);
	}
	return (0);
}
