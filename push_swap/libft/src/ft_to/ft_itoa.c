/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:52:47 by javperez          #+#    #+#             */
/*   Updated: 2023/09/28 11:56:17 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_num_digits(int n)
{
	int	digits;

	digits = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		digits++;
	}
	if (n == 0)
		return (1);
	while (n > 9)
	{
		n = n / 10;
		digits++;
	}
	digits++;
	return (digits);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			size;
	long long	num;

	num = n;
	size = count_num_digits(num);
	str = malloc((sizeof(char) * size) + 1);
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	str[size] = '\0';
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	size--;
	while (num)
	{
		str[size] = ((num % 10) + '0');
		num = num / 10;
		size--;
	}
	return (str);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(0));
}*/