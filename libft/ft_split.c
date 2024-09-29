/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:47:50 by javperez          #+#    #+#             */
/*   Updated: 2023/10/11 12:18:59 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (words);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	strs = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!strs)
		return (NULL);
	while (++j < ft_count_word(s, c))
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!(strs[j]))
		{
			ft_free(strs, j);
			return (NULL);
		}
		i += size;
	}
	strs[j] = NULL;
	return (strs);
}
/*
int	main(void)
{
	char *s = "Hola como estas";
	char c = ' ';
	//char	**str;

	printf("%d\n", ft_size_word(s, c, 0));
	//str = ft_split(s, c);
	//printf ("%s\n", str[0]);
	return (0);
}*/
