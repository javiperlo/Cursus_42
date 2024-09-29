/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:28:02 by javperez          #+#    #+#             */
/*   Updated: 2023/10/13 11:53:51 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (*needle == '\0' || needle == NULL)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i ++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str1[] = "aaxx"; //Cadena larga (haystack)
	char	str2[] = "xx"; //Cadena a buscar (needle)
	size_t	len = 3;
	//printf ("La funcion ORIGINAL: %s\n", strnstr(str1, str2, len));
	printf ("Mi funcion: %s", ft_strnstr((char *)str1, (char *)str2, len));
}*/
// El (size_t)ft_strlen(needle) + 1 >= len --> Para evitar el overlaping
/*
Busca la secuencia de carácteres 
contenida en la subcadena en una cadena de texto.

Esta función determinará si la cadena contiene a 
la subcadena (como "CASA" contiene "ASA") y, en caso afirmativo
indicará en que posición aparece la subcadena 
dentro de la cadena (de 0 en adelante, 1 en el ejemplo anterior).
En caso de aparecer la subcadena varias veces, 
la función siempre retornará la posición primera.

En este ejemplo se utiliza la función strnstr() 
para que determine dónde se encuentra la subcadena "es" dentro de micadena.
Retornará la posición 5, debido a 
que la función distingue entre mayúsculas y minúsculas
por lo que no se reconoce la subcadena 
"Es" (de "Esta") que se encuentra en la posición 0 de la cadena.
*/