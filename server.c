/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:08:30 by brunogue          #+#    #+#             */
/*   Updated: 2025/02/28 18:29:20 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * Função auxiliar para anexar um caractere à mensagem acumulada.
 * Se 'msg' for NULL, cria uma nova string com o caractere.
 */
char	*ft_strjoin_letter(char *msg, char c)
{
	size_t	len;
	char	*new_msg;

	len = msg ? strlen(msg) : 0;
	new_msg = malloc(len + 2);
	if (!new_msg)
		return (NULL);
	if (msg)
	{
		strcpy(new_msg, msg);
		free(msg);
	}
	new_msg[len] = c;
	new_msg[len + 1] = '\0';
	return (new_msg);
}

/*
 * Handler de sinais: reconstrói um caractere bit a bit e acumula os caracteres em uma mensagem.
 * Utiliza SIGUSR2 para representar o bit 1 e SIGUSR1 para representar o bit 0.
 * Ao receber o caractere nulo ('\0'), imprime a mensagem completa e libera o buffer.
 */
void	ft_receive(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit_count = 0;
	static char	*message = NULL;

	(void)info;
	(void)context;
	if (signal == SIGUSR2)
		c |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		message = ft_strjoin_letter(message, c);
		if (!message)
			exit(EXIT_FAILURE);
		if (c == '\0')
		{
			write(1, message, strlen(message));
			write(1, "\n", 1);
			free(message);
			message = NULL;
		}
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	printf("Server PID: %d\n", getpid());
	/* Configura o handler usando sigaction com SA_SIGINFO */
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = ft_receive;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("Erro ao configurar SIGUSR1");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("Erro ao configurar SIGUSR2");
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
