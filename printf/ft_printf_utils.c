/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:57:16 by brunogue          #+#    #+#             */
/*   Updated: 2024/11/20 14:40:10 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
	{
		return (ft_putstr("(null)"));
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr_u(n / 10);
	}
	count += ft_putchar((n % 10) + '0');
	return (count);
}
