/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:41:46 by javperez          #+#    #+#             */
/*   Updated: 2023/11/08 11:29:46 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_putstr - Print a string to the standard output.
 *
 * This function prints a string to the standard output character by character.
 * If the input string is NULL, it prints "(null)" instead.
 *
 * @param str - The string to be printed.
 * @return The number of characters printed (excluding the null terminator).
 */

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		ft_putchar_fd(*str, 1);
		count++;
		str++;
	}
	return (count);
}
