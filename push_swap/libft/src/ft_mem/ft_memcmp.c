/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:23:14 by javperez          #+#    #+#             */
/*   Updated: 2023/10/04 13:11:58 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)

{
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	char str1[] = "abcdef";
	char str2[] = "abc\375xx";
	int n;
	int puntero;

	n = 5;
	printf("La función ORIGINAL: %d\n", memcmp(str1, str2, n));
	puntero =  ft_memcmp(str1, str2, n);
	printf("La función MIA: %d\n", puntero); 
}*/