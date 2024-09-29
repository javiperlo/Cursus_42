/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:37:38 by javperez          #+#    #+#             */
/*   Updated: 2023/10/04 13:00:25 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (dst[0] == '\0' && src[0] == '\0')
		return (0);
	else if (dstsize == 0)
	{
		len = ft_strlen(src);
		return (len);
	}
	while (src[len] != '\0')
		len++;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/**
 * while (src[i] != '\0' && i < (dstsize - 1)) -_>
 * El dstsize - 1 es para reservar un
 * byte para el caracter nulo final.
 * ft_strlcpy: Devuelve la longitud de la cadena
 * src.
*/

//int main()
//{
//	char src[] = "holaaaass";
//	char dst[] = "javierr";
//	size_t dstsize = 4;
//	printf ("Src vale: %s\n", src);
//	printf ("Dst vale: %s\n\n", dst);
//	printf("ft_strlcpy: %zu ", ft_strlcpy(dst, src, dstsize));
//	printf("strlcpy: %zu\n", strlcpy(dst, src, dstsize));
//	return (0);
//}