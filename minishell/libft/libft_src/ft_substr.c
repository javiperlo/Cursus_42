/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:54:33 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:23:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*p;
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	p = (char *) s;
	if (start >= size)
		ret = (char *) malloc(1);
	else if (len >= size)
		ret = (char *) malloc(size + 1);
	else
		ret = (char *) malloc(len + 1);
	if (!ret || !p)
		return (0);
	i = 0;
	while (i < len && start + i < size)
	{
		ret[i] = p[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

/* #include <stdio.h>
int	main(void)
{
	char * s = "the longer string";
	unsigned int start = 1000;
	size_t len = 42000;
	printf("ret |%s|\n", ft_substr(s, start, len));
	return 0;
} */
