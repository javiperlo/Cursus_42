/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:39:21 by javperez          #+#    #+#             */
/*   Updated: 2023/10/12 19:06:21 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;
	char			*s;

	i = 0;
	s = (char *)str;
	while (i < n)
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i ++;
	}
	return (NULL);
}
/**
 * Busca la primera coincidencia del caracter 'c'
 * dentro de la cadena str. Con un limite de
 * caracteres 'n'. Si no encuentra esa letra
 * dentro del limite de caracteres, retornará NULL.
 * Si la encuentra devolvera un puntero a la dirección
 * de memoria del caracter iterado.
*/
/*
int	main(void)
{
	char cadena[] = "Hollslllllllaa";
	char *puntero; 
	//char *puntero_funcion_original;
	
	char	caracter = 's';
	int	len = 3;
	puntero = (char *)ft_memchr( cadena, caracter, len);
	//puntero_funcion_original = (char *)memchr(cadena, caracter, len);
	//printf( "La cadena original es: %s", cadena); 
	printf( "%s", puntero ); 
	//printf( "%s", puntero_funcion_original); 
	return 0;
}*/