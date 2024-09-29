/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:52:39 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:23:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *) s;
	i = 0;
	while (i < n)
	{
		if (*p == (char) c)
			return (p);
		p ++;
		i ++;
	}
	return (0);
}

/* #include <stdio.h>
int main(void)
{
	printf("%s\n", ft_memchr("this is string", 'i', 14));
	return 0;
}
 */
