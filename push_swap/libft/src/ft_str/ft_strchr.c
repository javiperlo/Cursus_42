/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:25:30 by javperez          #+#    #+#             */
/*   Updated: 2023/10/04 13:06:10 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/**
 * En primer lugar, verificamos si s[i]
 * es == a (char) c, por que podria ser que
 * sea la primera coincidencia en la cadena,
 * es decir en la posición 0.
 * 
 * Si s[i] == (char)c, devolvemos un puntero
 * a la dirección de memoria de s[i].
 * Y retornamos ese valor
*/
/*
int main(void)
{
	char	str[] = "teste";
	int		c = 'e';
	//ft_strchr(str, c);
	//printf("Funcioón ORIGINAL: %s", strchr(str, c));
	printf("Función MIA: %s", ft_strchr(str, c));
}*/