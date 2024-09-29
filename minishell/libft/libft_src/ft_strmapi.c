/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:54:09 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:23:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		size;
	char	*res;

	size = 0;
	while (s[size])
		size++;
	res = (char *)malloc(size + 1);
	if (!res)
		return (0);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/* #include <stdio.h>

char	ft_tolower(unsigned int i, char c)
{
	if (c >= 'A' && c <= 'Z' && i % 2 == 0)
		c += 32;
	return (c);
}

int	main(void)
{
	printf("%s", ft_strmapi("HELLO", ft_tolower));
	return(0);
}
 */
