/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:55:05 by javperez          #+#    #+#             */
/*   Updated: 2023/10/13 11:26:46 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
/*
int main()
{
	char str[] = "Hola";
	//int len = 1;
	//printf("Antes:%s\n", str);
	//ft_bzero(str, len);
	//printf ("Funcion Original: %s\n", bzero(str, len));
	write(1, "Antes: ", 7);
	write(1, &str ,4);
	write(1, "\nDespués: ", );
	ft_bzero(str, ft_strlen(str));
	write(1, &str ,4);
	//printf("Después: %s", str);
	return (0);
}*/