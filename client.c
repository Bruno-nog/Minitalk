/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:08:23 by brunogue          #+#    #+#             */
/*   Updated: 2025/02/28 18:29:37 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * Envia um caractere para o servidor, bit a bit.
 * Para cada bit (do mais significativo ao menos), envia:
 *   - SIGUSR2 se o bit for 1
 *   - SIGUSR1 se o bit for 0
 * Usa usleep para dar um intervalo entre os sinais.
 */
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
				perror("Erro ao enviar SIGUSR2");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				perror("Erro ao enviar SIGUSR1");
				exit(EXIT_FAILURE);
			}
		}
		usleep(100);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
	{
		write(2, "Usage: ./client <server PID> <message>\n", 41);
		return (1);
	}
	server_pid = (pid_t)atoi(argv[1]);
	if (server_pid <= 0)
	{
		write(2, "Invalid PID\n", 12);
		return (1);
	}
	message = argv[2];
	while (*message)
	{
		send_char(server_pid, *message);
		message++;
	}
	/* Envia o caractere nulo para indicar o fim da mensagem */
	send_char(server_pid, '\0');
	return (0);
}
