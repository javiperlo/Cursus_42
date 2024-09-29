/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:53:54 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:23:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	start;
	size_t	i;
	int		ret;

	if (!dstsize && !dst)
		return (0);
	start = ft_strlen(dst);
	if (start >= dstsize)
		return (dstsize + ft_strlen(src));
	else
		ret = start + ft_strlen(src);
	i = 0;
	while (src[i] && (start + i) < dstsize - 1)
	{
		dst[start + i] = src[i];
		i ++;
	}
	dst[start + i] = '\0';
	return (ret);
}
