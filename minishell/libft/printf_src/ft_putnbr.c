/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:33:26 by javperez          #+#    #+#             */
/*   Updated: 2024/05/07 19:33:27 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	pow_ten(int index)
{
	if (index == 0)
		return (1);
	if (index == 1)
		return (10);
	return (10 * pow_ten(index - 1));
}

static int	count_digits(long int n)
{
	int	num_digits;

	num_digits = 0;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		num_digits++;
		n = n / 10;
	}
	return (num_digits);
}

static void	print_str(long int n, int num_digits, int fd)
{
	char	c;

	while (num_digits > 0)
	{
		c = 48 + (n / (pow_ten(num_digits - 1)));
		n = n % pow_ten(num_digits - 1);
		num_digits--;
		write(fd, &c, 1);
	}
}

int	ft_putnbr(int n)
{
	int			num_digits;
	long int	num;
	int			count;

	count = 0;
	num_digits = count_digits((long int) n);
	if (n == 0)
		num_digits = 1;
	num = n;
	if (n < 0)
	{
		write(1, "-", 1);
		num = num * -1;
		count++;
	}
	print_str(num, num_digits, 1);
	return (num_digits + count);
}
