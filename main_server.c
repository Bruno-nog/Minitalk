/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:25:25 by brunogue          #+#    #+#             */
/*   Updated: 2025/03/07 16:37:15 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = ft_receive;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error when configuring SIGUSR1");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error when configuring SIGUSR2");
		exit(EXIT_FAILURE);
	}
	signal(SIGINT, clean_exit);
	while (1)
		pause();
	return (0);
}
