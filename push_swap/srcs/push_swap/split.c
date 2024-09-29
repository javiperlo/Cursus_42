/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:57:03 by javperez          #+#    #+#             */
/*   Updated: 2024/02/03 15:02:34 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	count_words(char *str, char c)
{
	int		count;
	int		inside_word;

	count = 0;
	while (*str)
	{
		inside_word = 0;
		while (*str == c)
			str++;
		while (*str != c && *str)
		{
			if (!inside_word)
			{
				count++;
				inside_word = 1;
			}
			str++;
		}
	}
	return (count);
}

char	*get_next_word(char *str, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == c)
		cursor++;
	while ((str[cursor + len] != c) && str[cursor + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((str[cursor] != c) && str[cursor])
		next_word[i++] = str[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(char *str, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = count_words(str, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(str, c);
	}
	result_array[i] = NULL;
	return (result_array);
}
