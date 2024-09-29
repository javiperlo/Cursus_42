/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:33:30 by javperez          #+#    #+#             */
/*   Updated: 2024/05/07 19:33:33 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	count_digits(unsigned long int n)
{
	int	num_digits;

	num_digits = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		num_digits++;
		n = n / 16;
	}
	return (num_digits);
}

static void	print_pointer(unsigned long nbr, char *base)
{
	if (nbr < 16)
		write(1, &base[nbr], 1);
	else
	{
		print_pointer(nbr / 16, base);
		print_pointer(nbr % 16, base);
	}
}

int	ft_putpointer(unsigned long nbr)
{
	char		*base;

	base = "0123456789abcdef";
	print_pointer(nbr, base);
	return (count_digits(nbr));
}
