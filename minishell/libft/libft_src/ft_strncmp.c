/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:54:13 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:23:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i ++;
	}
	if (s1[i] && !s2[i] && i < n)
		return ((unsigned char)s1[i]);
	if (s2[i] && !s1[i] && i < n)
		return (0 - (unsigned char)s2[i]);
	return (0);
}

/* #include <stdio.h>
#include <string.h>
int main()
{
	char *a = "\200";
	char *b = "\20";
	printf("%d\n",ft_strncmp(a, b, 5));
	printf("%d\n",strncmp(a, b, 5));
	return 0;
} */
