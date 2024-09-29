/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:19:33 by javperez          #+#    #+#             */
/*   Updated: 2023/10/10 14:55:07 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len --;
		}
	}
	return (dst);
}

/*
int	main(void)
{
    char	src[] = "Hello World";
    char	dst[] = "babiel";
    size_t	len;

    len = 2;
    printf("Before memmove dst = %s, src = %s\n", dst, src);
    ft_memmove(src, src+2 , len);
    printf("After memmove dst = %s\n", src);
    return (0);
}*/