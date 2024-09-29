/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:37:17 by javperez          #+#    #+#             */
/*   Updated: 2023/11/07 16:56:46 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_putchar - Print a character
 *
 * This function writes a single character to the standard output using write()
 *
 * @param c - The character to be printed.
 * @return The number of characters written (always 1).
 */

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}
