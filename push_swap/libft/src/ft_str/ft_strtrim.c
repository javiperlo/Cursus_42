/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:27:55 by javperez          #+#    #+#             */
/*   Updated: 2023/10/13 11:51:24 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * This funcion returns the string s1 without the characters
 * of set at the beginning and the end of the string.
 * Search for the first character that is not in set
 * and search for the last character that is not in set.
 * And then return a substring from the first character
 * to the last character. Withouth the characters of set.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i - 1]))
		i--;
	return (ft_substr(s1, 0, i));
}
/*
int	main(void)
{
	char	s1[] = "  v ho v       v la  ";
	char	set[]= " ";

	//ft_strtrim(s1, set);
	printf ("%s", ft_strtrim(s1, set));
}*/