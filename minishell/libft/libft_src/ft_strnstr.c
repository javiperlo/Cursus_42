/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:54:18 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:23:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nsize;
	size_t	hsize;
	char	*h;

	h = (char *) haystack;
	if (!len && !h)
		return (0);
	i = 0;
	nsize = ft_strlen((char *)needle);
	hsize = ft_strlen(haystack);
	if (!hsize && !nsize)
		return ("");
	if (!hsize)
		return (0);
	while (i + nsize <= len)
	{
		if (h[0] && ft_strncmp(h, (char *)needle, nsize) == 0)
			return (h);
		i++;
		h++;
	}
	return (0);
}

/* #include <string.h>
int main()
{
	char *h = "";
	char *n = "asdf";
	size_t	len = 4563;
	printf("%s\n",ft_strnstr(h, n, len));
	printf("%s\n",strnstr(h, n, len));
	return 0;
} */

/*
h 0, n 0, l 0 -> empty | null
h 0, n 0, l x ->empty | ??
h 0, n x, l x -> null | null

h 0, n 0, l x -> empty | empty
h x, n 0, l 0 -> null | null


*/
