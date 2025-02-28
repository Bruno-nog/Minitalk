/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:08:59 by brunogue          #+#    #+#             */
/*   Updated: 2025/02/28 18:13:44 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>

//SERVER
void	ft_receive(int signal, siginfo_t *info, void *context);
char	*append_char(char *msg, char c);

//CLIENT

#endif