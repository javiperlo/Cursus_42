/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:22:46 by javperez          #+#    #+#             */
/*   Updated: 2023/09/26 15:00:19 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\r' || nptr[i] == '\n' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
	{
		if (nptr[i + 1] == '+')
			return (0);
		sign = -1;
		i++;
	}
	if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
int	main(void)
{
	char	nptr[] = "\t\v\n\r\f123";
	printf("MI ATOI\n");
	printf ("%d", ft_atoi(nptr));
	printf("\nATOI ORIGINAL\n");
	printf("%d", atoi(nptr));
}*/
