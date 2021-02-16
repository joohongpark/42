/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 01:45:32 by joopark           #+#    #+#             */
/*   Updated: 2021/02/16 14:51:44 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int				main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
	int			gnl;
	char		*line;
	char		*bp;
	char *arg1 = "/bin/sleep";
	char *arg2 = "sub process";
	char *arg[3];
	arg[0] = arg1;
	arg[1] = arg2;
	arg[2] = NULL;
	
	ft_signal();
	while (1)
	{
		ft_putstr_fd("\n$> ", 1);
		gnl = ft_get_next_line(0, &line, &bp);
		if (gnl == -1)
			exit(EXIT_FAILURE);
		write(1, line, ft_strlen(line));
		ft_exec("/bin/echo", arg, envp);
		free(line);
	}
	return (0);
}
