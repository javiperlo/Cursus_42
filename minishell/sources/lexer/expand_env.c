/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:39:51 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:21:54 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*replace_env(char *str, int *i, char *exp, int len)
{
	char	*full;
	int		j;
	int		k;

	full = (char *)ft_calloc((ft_strlen(str) - len)
			+ ft_strlen(exp) + 2, sizeof(char));
	if (!full)
		ft_error(1);
	j = -1;
	k = (*i) - len - 1;
	while (full && ++j < k)
		full[j] = str[j];
	k = 0;
	while (full && k < (int)ft_strlen(exp))
		full[j++] = exp[k++];
	k = (*i);
	while (full && k < (int)ft_strlen(str))
		full[j++] = str[k++];
	if (str)
		free(str);
	if (exp)
		free(exp);
	*i = 0;
	return (full);
}

int	found_env(char *old, int *i, t_word *word, t_utils *utils)
{
	int		len;
	char	*var;
	int		j;
	char	*env;

	len = found_env_helper(word, old, i);
	if (len < 0)
		return (1);
	var = (char *)ft_calloc(len + 1, sizeof(char));
	if (!var)
		return (!ft_error(1));
	j = 0;
	(*i)++;
	while (j < len)
		var[j++] = old[(*i)++];
	env = ft_getenv(var, utils);
	if (!env)
		return (0);
	word->cont = replace_env(old, i, env, len);
	free(var);
	if (!word->cont)
		return (0);
	return (1);
}

int	expand_env_str(t_word *word, t_utils *utils)
{
	int		i;

	i = 0;
	while (word->cont && word->cont[i])
	{
		if (word->cont[i] == '$' && word->cont[i + 1]
			&& word->cont[i + 1] == '?')
			word->cont = expand_err(word->cont, &i);
		else if (word->cont[i] == '$' && word->cont[i + 1]
			&& check_valid_identifier(word->cont[i + 1]))
			i = i + 2;
		else if (word->cont[i] == '$' && word->cont[i + 1])
		{
			if (!found_env(word->cont, &i, word, utils))
				return (0);
		}
		else
			i++;
	}
	return (1);
}

int	expand_var_quote(t_word *word, t_utils *utils)
{
	int		i;

	if (!ft_strchr(word->cont, '$'))
		return (1);
	i = 0;
	while (word->cont[i])
	{
		if (word->cont[i] == '$' && word->cont[i + 1]
			&& word->cont[i + 1] == '?')
			word->cont = expand_err(word->cont, &i);
		else if (word->cont[i] == '$'
			&& !found_env(word->cont, &i, word, utils))
			return (0);
		else if (word->cont[i] == '\'')
			skip_quotes(&i, word->cont);
		else if (word->cont[i] == '\"')
			word->cont = expand_env_quotes(word, &i, utils);
		else
			i++;
	}
	return (1);
}

int	expand_env(t_split *split, t_utils *utils)
{
	t_word	*ptr;
	int		success;

	success = 1;
	ptr = split->first;
	while (ptr)
	{
		if (ptr->type == STR || ptr->type == CMD
			|| ptr->type == ARG || ptr->type == PATH)
			success = expand_env_str(ptr, utils);
		else if (ptr->type == QUOTE)
			success = expand_var_quote(ptr, utils);
		if (!success)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
