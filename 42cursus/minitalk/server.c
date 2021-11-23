/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:23:14 by joopark           #+#    #+#             */
/*   Updated: 2021/11/23 12:44:54 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "utils.h"

void	transmit(int pid, int signum)
{
	if (kill(pid, signum) == -1)
	{
		ft_putstr_fd("[ALERT] TRANSMIT FAIL\n", 2);
	}
}

static void	server(int sig, siginfo_t *info_struct, void *fun)
{
	static char				counter = 0;
	static unsigned char	receive_char = 0;

	(void) fun;
	receive_char <<= 1;
	receive_char |= (sig == SIGUSR2);
	if (++counter == 8)
	{
		if (receive_char == '\0')
		{
			write(1, "\n", 1);
			transmit(info_struct->si_pid, SIGUSR2);
		}
		else
		{
			write(1, &receive_char, 1);
			transmit(info_struct->si_pid, SIGUSR1);
		}
		counter = 0;
		receive_char = 0;
	}
}

int	main(void)
{
	struct sigaction		sigaction_t;
	int						pid;
	
	pid = getpid();
	if (pid == -1)
	{
		ft_putstr_fd("[ALERT] getpid() FAIL\n", 2);
		return (0);
	}
	ft_putstr_fd("[Server] PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	sigaction_t.sa_sigaction = server;
	sigaction_t.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sigaction_t, 0) == -1
		|| sigaction(SIGUSR2, &sigaction_t, 0) == -1)
	{
		write(2, "[ALERT] sigaction() FAIL\n", 25);
		return (0);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
