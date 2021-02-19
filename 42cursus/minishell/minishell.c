/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 01:45:32 by joopark           #+#    #+#             */
/*   Updated: 2021/02/18 23:00:48 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>

int				main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
	(void) envp;
	char		*bp;
	char		*line;
	char		*exec;
	char		*arg[] = {
		"/bin/echo",
		"sub process",
		NULL
	};

	ft_signal();
	printf("%s\n", ft_find_exec(envp, "bash"));
	while (1)
	{
		ft_putstr_fd("\n$> ", 1);
		line = ft_getline(&bp);
		write(1, line, ft_strlen(line));
		ft_exec("/bin/echo", arg, envp);
		free(line);
	}
	return (0);
}
