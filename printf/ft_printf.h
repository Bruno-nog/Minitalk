/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:45:41 by brunogue          #+#    #+#             */
/*   Updated: 2024/11/20 15:03:34 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_u(unsigned int n);
int		ft_hex(unsigned long n, const char *base);
int		ft_putnbr(int n);
void	ft_pointer_type(va_list args, int *count);
void	ft_type_data(va_list args, int *count, const char *format, int *i);
int		ft_printf(const char *format, ...);

#endif
