/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:52:56 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:23:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_memmove2(char *s, char *d, size_t len)
{
	while (len > 0)
	{
		d[len - 1] = s[len - 1];
		len--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (!d && !s)
		return (0);
	if (s > d)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		ft_memmove2(s, d, len);
	return (dst);
}

/* #include <stdio.h>
int	main(void)
{
	int size = 15;
	char dest[size];
	char src[] = "source";
	printf("%s\n", ft_memmove(dest, src, size));
	return (0);
}
 */
