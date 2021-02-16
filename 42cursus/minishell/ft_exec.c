/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:33:02 by joopark           #+#    #+#             */
/*   Updated: 2021/02/16 14:43:05 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t			ft_exec(char *file, char *argv[], char *envp[])
{
	pid_t		rtn;

	rtn = fork();
	if (rtn == 0)
		execve(file, argv, envp);
	return (rtn);
}