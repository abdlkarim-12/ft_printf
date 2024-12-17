/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenzao <aguenzao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:27:21 by aguenzao          #+#    #+#             */
/*   Updated: 2024/12/17 11:23:29 by aguenzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_check(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'x' || c == 'X')
		count += ft_hexadecimal(va_arg(args, unsigned int), c);
	else if (c == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putaddress(va_arg(args, unsigned long long));
	}
	else if (c == '%')
		return (ft_putchar('%'));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	if (write(1, 0, 0) == -1)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				count += ft_check(args, format[++i]);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
