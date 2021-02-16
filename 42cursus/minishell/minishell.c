/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 01:45:32 by joopark           #+#    #+#             */
/*   Updated: 2021/02/10 23:52:22 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int				main(int argc, char *argv[], char *envp[])
{
	pid_t		pid;
	(void) argc;
	(void) argv;
	char *arg1 = "/bin/sleep";
	char *arg2 = "10";
	char *arg[3];
	arg[0] = arg1;
	arg[1] = arg2;
	arg[2] = NULL;
	
	printf("1. before exec/fork\n");
	pid = fork();
	if (pid == 0)
		execve("/bin/sleep", arg, envp);
	sleep(10);
	printf("2. after exec\n");
	return (0);
}
