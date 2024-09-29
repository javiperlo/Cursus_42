/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:03:36 by javperez          #+#    #+#             */
/*   Updated: 2023/09/19 19:34:31 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	c: El carácter a enviar.
	fd: El file descriptor sobre el que escribir.
*/

/* Funciones autorizadas: Write. 
** Descripción: Envía el caracter 'c' al file descriptor
** especificado.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
int	main(void)
{
	char	c = 'd';
	int		fd = 1; // Estoy mandando el file descriptor al stdin
	
	ft_putchar_fd(c, fd);
}*/