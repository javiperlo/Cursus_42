/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:07:06 by javperez          #+#    #+#             */
/*   Updated: 2023/09/26 13:22:13 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		*ptr;
	int		i;

	i = 0;
	ptr = malloc((ft_strlen(s) * sizeof(char)) + 1);
	if (!ptr)
		return (NULL);
	while (i < ft_strlen(s))
	{
		((char *)ptr)[i] = s[i];
		i++;
	}
	((char *)ptr)[i] = '\0';
	return ((char *)ptr);
	free(ptr);
}
/*
int	main(void)
{
	char	array1[] = "";
	char	*p;

	//ft_strdup(array1);
	printf ("The string allocated in array1 is: %s\n", array1);
	p = ft_strdup(array1);
	printf ("The string allocated in *p is: %s\n", p);
}*/
/*
	strdup() --> Viene de string duplicate
	Devuelve un puntero a una nueva cadena
	de caracteres que es un duplicado
	de la cadena de caracteres apuntada por 
	array1.
*/