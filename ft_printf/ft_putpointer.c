/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:03:55 by javperez          #+#    #+#             */
/*   Updated: 2023/11/10 18:48:28 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_countpoi - Count the number of digits in 
 * a hexadecimal representation of a pointer.
 *
 * This function counts the number of digits required to represent a pointer in
 * hexadecimal format.
 *
 * @param num - The unsigned long integer representing the pointer value.
 * @return The count of hexadecimal digits in the pointer representation.
 */

int	ft_countpoi(unsigned long num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		count++;
		num = num / 16;
	}
	return (count);
}
/**
 * ft_putpointer - Print a pointer in hexadecimal format.
 *
 * This function prints an unsigned long integer (pointer) in hexadecimal format.
 *
 * @param num - The unsigned long integer representing the pointer value.
 * @return The number of characters printed.
 */

int	ft_putpointer(unsigned long num)
{
	if (num >= 16)
	{
		ft_putpointer(num / 16);
		ft_putpointer(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + 48);
		else
			ft_putchar(num - 10 + 'a');
	}
	return (ft_countpoi(num));
}
/**
 * ft_putpoi - Print a pointer with a "0x" prefix in hexadecimal format.
 *
 * This function prints a pointer with a "0x" prefix in hexadecimal format.
 *
 * @param num - The unsigned long integer representing the pointer value.
 * @return The number of characters printed.
 */

int	ft_putpoi(unsigned long num)
{
	int		len;

	len = 0;
	if (num == 0)
	{
		len = len + write (1, "0x0", 3);
		return (len);
	}
	len = write (1, "0x", 2);
	len = len + ft_putpointer(num);
	return (len);
}
