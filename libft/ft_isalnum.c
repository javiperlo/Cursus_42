/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:58:32 by javperez          #+#    #+#             */
/*   Updated: 2023/09/25 17:14:42 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) || (c >= 48 && c <= 57))
	{
		return (1);
	}
	return (0);
}
/*
int	main()
{
	char	c;
	c = '.';
	int		res;

	res = ft_isalpha(c);
	printf ("%d\n", res);
	return (0);
}*/