/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:50:15 by javperez          #+#    #+#             */
/*   Updated: 2023/09/19 19:54:35 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write (fd, &s[i], 1);
			i ++;
		}
	}
	write (fd, "\n", 1);
}
/*
int	main(void)
{
	char	*s = "Hola Mundo";
	int		fd = 1;

	ft_putendl_fd(s, fd);
}*/