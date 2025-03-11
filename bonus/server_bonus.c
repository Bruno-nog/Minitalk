/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:52:03 by brunogue          #+#    #+#             */
/*   Updated: 2025/03/07 18:56:17 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static char	**ft_message_ptr(void)
{
	static char	*message = NULL;

	return (&message);
}

char	*ft_strjoin_letter(char *msg, char c)
{
	size_t	len;
	char	*new_msg;

	if (msg == NULL)
		len = 0;
	else
		len = ft_strlen(msg);
	new_msg = malloc(len + 2);
	if (!new_msg)
		return (NULL);
	if (msg)
	{
		ft_strcpy(new_msg, msg);
		free(msg);
	}
	new_msg[len] = c;
	new_msg[len + 1] = '\0';
	return (new_msg);
}

void	add_char_to_message(char c, char **message)
{
	*message = ft_strjoin_letter(*message, c);
	if (!*message)
		exit(EXIT_FAILURE);
	if (c == '\0')
	{
		write(1, *message, ft_strlen(*message));
		write(1, "\n", 1);
		free(*message);
		*message = NULL;
	}
}

void	clean_exit(int signum)
{
	char	**message;

	(void)signum;
	message = ft_message_ptr();
	if (*message)
	{
		free(*message);
		*message = NULL;
	}
	ft_printf("\nServer shutting down...\n");
	exit(EXIT_SUCCESS);
}

void	ft_receive(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit_count = 0;
	char		**message;

	(void)context;
	message = ft_message_ptr();
	if (signal == SIGUSR2)
		c |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		add_char_to_message(c, message);
		if (c == '\0')
		{
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_printf("Failed to send ack\n");
		}
		bit_count = 0;
		c = 0;
	}
}
