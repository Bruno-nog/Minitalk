/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:26:54 by brunogue          #+#    #+#             */
/*   Updated: 2025/03/11 17:26:03 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../printf/ft_printf.h"

//SERVER BONUS
void	ft_receive(int signal, siginfo_t *info, void *context);
void	clean_exit(int signum);

//UTILS
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, const char *src);

#endif