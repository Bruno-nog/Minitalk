/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:04:19 by brunogue          #+#    #+#             */
/*   Updated: 2025/02/25 13:01:53 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned long n, const char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_hex(n / 16, base);
	}
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
		count++;
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
	}
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

void	ft_pointer_type(va_list args, int *count)
{
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(args, void *);
	if (ptr == 0)
		*count += ft_putstr("(nil)");
	else
	{
		*count += ft_putstr("0x");
		*count += ft_hex(ptr, "0123456789abcdef");
	}
}

void	ft_type_data(va_list args, int *count, const char *format, int *i)
{
	if (format[*i] == '%')
	{
		(*i)++;
		if (format[*i] == 'c')
			*count += ft_putchar(va_arg(args, int));
		else if (format[*i] == 's')
			*count += ft_putstr(va_arg(args, char *));
		else if (format[*i] == 'd' || format[*i] == 'i')
			*count += ft_putnbr(va_arg(args, int));
		else if (format[*i] == 'u')
			*count += ft_putnbr_u(va_arg(args, unsigned int));
		else if (format[*i] == 'p')
			ft_pointer_type(args, count);
		else if (format[*i] == 'x')
			*count += ft_hex(va_arg(args, unsigned int), "0123456789abcdef");
		else if (format[*i] == 'X')
			*count += ft_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
		else if (format[*i] == '%')
			*count += ft_putchar('%');
		else
			*count += ft_putchar('%');
	}
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				count;
	int				i;

	count = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_type_data(args, &count, format, &i);
		}
		else
		{
			count += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
