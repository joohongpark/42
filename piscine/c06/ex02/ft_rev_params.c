/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:23:20 by joopark           #+#    #+#             */
/*   Updated: 2020/08/10 16:24:17 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			main(int argc, char *argv[])
{
	int		len;

	while (--argc > 0)
	{
		len = 0;
		while (argv[argc][len] != 0)
			len++;
		write(1, argv[argc], len);
		write(1, "\n", 1);
	}
	return (0);
}
