/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:33:21 by javperez          #+#    #+#             */
/*   Updated: 2024/05/07 19:33:23 by javperez         ###   ########.fr       */
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

static void	print_num(unsigned int nbr, char *base)
{
	if (nbr < 16)
		write(1, &base[nbr], 1);
	else
	{
		print_num(nbr / 16, base);
		print_num(nbr % 16, base);
	}
}

int	ft_puthex_low(unsigned int nbr)
{
	char		*base;

	base = "0123456789abcdef";
	print_num(nbr, base);
	return (count_digits(nbr));
}

int	ft_puthex_up(unsigned int nbr)
{
	char		*base;

	base = "0123456789ABCDEF";
	print_num(nbr, base);
	return (count_digits(nbr));
}
