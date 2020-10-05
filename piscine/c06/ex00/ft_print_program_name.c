/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:18:45 by joopark           #+#    #+#             */
/*   Updated: 2020/08/10 16:19:12 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			main(int argc, char *argv[])
{
	int		len;

	len = 0;
	while (argv[0][len] != 0)
		len++;
	if (argc > 0)
		write(1, argv[0], len);
	write(1, "\n", 1);
	return (0);
}
