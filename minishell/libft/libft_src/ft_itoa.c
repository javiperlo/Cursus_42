/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:51:45 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:23:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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

static void	init_str(int i, char *res, long int n, int num_digits)
{
	while (num_digits > 0)
	{
		res[i] = 48 + (n / (pow_ten(num_digits - 1)));
		n = n % pow_ten(num_digits - 1);
		num_digits--;
		i++;
	}
}

char	*ft_itoa(int n)
{
	int			num_digits;
	long int	num;
	char		*res;
	int			i;

	num_digits = count_digits((long int) n);
	if (n == 0)
		num_digits = 1;
	i = 0;
	num = n;
	if (n < 0)
	{
		i++;
		num = num * -1;
	}
	res = (char *)malloc(num_digits + i + 1);
	if (!res)
		return (0);
	if (n < 0)
		res[0] = '-';
	init_str(i, res, num, num_digits);
	res[num_digits + i] = '\0';
	return (res);
}

/* #include <stdio.h>
int	main(void)
{
	int	n;

	n = 98798;
	printf("%s\n", ft_itoa(n));
	return (0);
} */
