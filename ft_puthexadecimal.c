/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenzao <aguenzao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:28:05 by aguenzao          #+#    #+#             */
/*   Updated: 2024/12/15 15:11:46 by aguenzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned int nb, char is_register)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_hexadecimal(nb / 16, is_register);
		count += ft_hexadecimal(nb % 16, is_register);
	}
	else
	{
		if (nb < 10)
			count += ft_putchar(nb + 48);
		else if (is_register == 'X')
			count += ft_putchar(nb + 55);
		else if (is_register == 'x')
			count += ft_putchar(nb + 87);
	}
	return (count);
}
