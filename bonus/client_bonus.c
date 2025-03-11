/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:52:05 by brunogue          #+#    #+#             */
/*   Updated: 2025/03/11 17:50:28 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ack_handler(int signum)
{
	(void)signum;
	ft_printf("Message received by server!\n");
	exit(EXIT_SUCCESS);
}

static void	send_char(pid_t server_pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_printf("Error sending SIGUSR2\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_printf("Error sending SIGUSR1\n");
				exit(EXIT_FAILURE);
			}
		}
		usleep(500);
		bit--;
	}
}

void	setup_signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "Error setting up SIGUSR1 handler\n", 34);
		exit(EXIT_FAILURE);
	}
}

void	send_message(pid_t server_pid, char *message)
{
	while (*message)
	{
		send_char(server_pid, *message);
		message++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		write(2, "Usage: ./client <server PID> <message>\n", 40);
		return (1);
	}
	server_pid = (pid_t)atoi(argv[1]);
	if (server_pid <= 0)
	{
		write(2, "Invalid PID\n", 12);
		return (1);
	}
	setup_signal_handler();
	send_message(server_pid, argv[2]);
	pause();
	return (0);
}
