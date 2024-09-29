/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:42:50 by javperez          #+#    #+#             */
/*   Updated: 2023/11/04 13:55:07 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_putdigitx - Print an integer in a 
 * specified base (lowercase hexadecimal).
 *
 * This function prints an integer in the specified 
 * base (base 10 or base 16) using
 * lowercase hexadecimal characters.
 *
 * @param num - The integer to be printed.
 * @param base - The base to use for printing (e.g., 10
 * for decimal or 16 for hexadecimal).
 * @return The number of characters printed.
 */

int	ft_putdigitx(long num, int base)
{
	char	*symbols;
	int		count;

	count = 0;
	symbols = "0123456789abcdef";
	if (num < 0)
	{
		write (1, "-", 1);
		count += 1;
		return (count + ft_putdigitx(-num, base));
	}
	else if (num < base)
		return (ft_putchar(symbols[num]));
	else
	{
		count = ft_putdigitx(num / base, base);
		return (count + ft_putdigitx(num % base, base));
	}
	return (count);
}
/**
 * ft_putdigit_mayuscx - Print an integer in a
 * specified base (uppercase hexadecimal).
 *
 * This function prints an integer in the
 * specified base (base 10 or base 16) using
 * uppercase hexadecimal characters.
 *
 * @param num - The integer to be printed.
 * @param base - The base to use for printing (e.g., 10
 * for decimal or 16 for hexadecimal).
 * @return The number of characters printed.
 */

int	ft_putdigit_mayuscx(long num, int base)
{
	char	*symbols;
	int		count;

	count = 0;
	symbols = "0123456789ABCDEF";
	if (num < 0)
	{
		write (1, "-", 1);
		count += 1;
		return (count + ft_putdigit_mayuscx(-num, base));
	}
	else if (num < base)
		return (ft_putchar(symbols[num]));
	else
	{
		count = ft_putdigit_mayuscx(num / base, base);
		return (count + ft_putdigit_mayuscx(num % base, base));
	}
	return (count);
}
