/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenzao <aguenzao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:27:12 by aguenzao          #+#    #+#             */
/*   Updated: 2024/12/17 11:29:37 by aguenzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_hexadecimal(unsigned int nb, char is_register);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_putaddress(unsigned long nb);
int	ft_printf(const char *format, ...);

#endif