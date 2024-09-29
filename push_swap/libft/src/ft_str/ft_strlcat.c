/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:12:17 by javperez          #+#    #+#             */
/*   Updated: 2023/09/27 19:52:31 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len_of_dest;
	size_t		len_of_src;

	len_of_dest = ft_strlen(dst);
	len_of_src = ft_strlen(src);
	i = 0;
	if (len_of_dest >= size)
		return (len_of_src + size);
	while (src[i] != '\0' && (len_of_dest + i) < (size - 1))
	{
		dst[len_of_dest + i] = src[i];
		i++;
	}
	dst[len_of_dest + i] = '\0';
	return (len_of_dest + len_of_src);
}
/*
int	main()
{
	char	src[] = "abcd";
	char	dst[] = "pqrstuvwxyz";
	int		size = 0;
	
	printf("La funcion strlcat saca esto: %lu\n", strlcat(dst, src, size));
	printf("Mi funcion saca este resultado: %lu\n",ft_strlcat(dst, src, size));

}*/