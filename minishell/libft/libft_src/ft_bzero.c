/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:51:08 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:24:02 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = 0;
		p ++;
		n --;
	}
}

/* int	main(void)
{
	char b[] = "hello this string";
	printf("%s\n", b);
	ft_bzero(b, 20);
	printf("%s\n", b);
	return 0;
}
 */
