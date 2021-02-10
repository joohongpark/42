/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 01:45:32 by joopark           #+#    #+#             */
/*   Updated: 2021/02/10 22:49:08 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int				main(int argc, char *argv[], char *envp[])
{
	int			p;
	int			gnl;
	char		*line;
	char		*bp;

	bp = NULL;
	line = NULL;

	p = 0;
	(void)argc;
	(void)argv;

	while (envp[p] != NULL)
	{
		printf("env : %s\n", envp[p]);
		p++;
	}
	while (1)
	{
		ft_putstr_fd("\n$> ", 1);
		gnl = ft_get_next_line(0, &line, &bp);
		if (gnl == -1)
			exit(EXIT_FAILURE);
		write(1, line, ft_strlen(line));
		free(line);
	}
	return (0);
}
