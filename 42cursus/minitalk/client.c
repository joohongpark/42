/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:23:14 by joopark           #+#    #+#             */
/*   Updated: 2021/11/23 12:38:00 by joopark          ###   ########.fr       */
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

void	ack_check(int sig)
{
	static long		send_str_len = 0;
	if (sig == SIGUSR1)
	{
		send_str_len++;
	}
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("[ALERT] string (size : ", 1);
		ft_putnbr_fd(send_str_len, 1);
		ft_putstr_fd(") transmit success\n", 1);
		send_str_len = 0;
	}
}

void	client(int pid, char *str)
{
	int				char_bits;
	char			send_char;

	while (1)
	{
		char_bits = 8;
		send_char = *str;
		while (char_bits--)
		{
			if (send_char >> char_bits & 1)
			{
				transmit(pid, SIGUSR2);
			}
			else
			{
				transmit(pid, SIGUSR1);
			}
			usleep(100);
		}
		if (*str == '\0')
		{
			break ;
		}
		str++;
	}
}

int	main(int argc, char* argv[])
{
	struct sigaction	sigaction_t;
	int					pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [MSG]\n", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1)
	{
		ft_putstr_fd("[ALERT] WRONG PID\n", 2);
		return (0);
	}
	sigaction_t.sa_flags = SA_SIGINFO;
	sigaction_t.sa_handler = ack_check;
	if ( sigaction(SIGUSR1, &sigaction_t, 0) == -1
		 || sigaction(SIGUSR2, &sigaction_t, 0) == -1)
	{
		ft_putstr_fd("[ALERT] sigaction() FAIL\n", 2);
		return (0);
	}
	client(pid, argv[2]);
	return (0);
}
