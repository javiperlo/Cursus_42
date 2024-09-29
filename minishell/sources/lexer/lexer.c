/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:41:35 by javperez          #+#    #+#             */
/*   Updated: 2024/05/09 20:02:03 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void free_split(t_split *split)
{
	t_word *del;
	t_word *ptr;

	if (!split)
		return;
	ptr = split->first;
	while (ptr)
	{
		free(ptr->cont);
		del = ptr;
		ptr = ptr->next;
		free(del);
	}
	free(split);
}

int split_words(char *input, t_split *split)
{
	int i;

	i = 0;
	while (input[i])
	{
		skip_space(input, &i);
		if (input[i])
		{
			if (!define_word(input, &i, split))
				return (0);
		}
	}
	return (1);
}

t_split *split_input(char *input, t_utils *utils)
{
	t_split *split;

	split = (t_split *)ft_calloc(1, sizeof(t_split));
	if (!split)
	{
		ft_error(1);
		return (0);
	}
	if (!split_words(input, split) || !check_split(split))
	{
		free_split(split);
		return (0);
	}
	if (!expand_env(split, utils) || !combine_quotes(split))
	{
		free_split(split);
		return (0);
	}
	sort_split(split);
	return (split);
}

void sort_split(t_split *split)
{
	t_word *ptr;

	ptr = split->first;
	if (ptr && ptr->type == STR)
		ptr->type = CMD;
	while (ptr)
	{
		if (ptr->prev && ptr->type == STR && ptr->prev->type == PIPE)
			ptr->type = CMD;
		else if (ptr->prev && ptr->prev->type == REDIR)
			ptr->type = PATH;
		else if (ptr->type == STR)
			ptr->type = ARG;
		ptr = ptr->next;
	}
}
