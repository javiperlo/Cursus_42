/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:40:31 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:21:54 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	invalid_char(char *input, char c)
{
	int		i;
	int		len;

	len = (int) ft_strlen(input);
	if (!ft_strchr(input, c))
		return (0);
	i = 0;
	while (i < len)
	{
		skip_space(input, &i);
		if (input[i] && is_quote(input[i]))
			skip_quotes(&i, input);
		if (input[i] && input[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	open_quotes(char *input)
{
	int	open;
	int	i;
	int	quote;

	open = 0;
	i = 0;
	while (input && input[i])
	{
		while (input[i] && !is_quote(input[i]))
			i++;
		if (is_quote(input[i]))
		{
			open = 1;
			quote = input[i];
			i++;
		}
		while (input[i] && input[i] != quote)
			i++;
		if (input[i] && input[i] == quote)
		{
			open = 0;
			i++;
		}
	}
	return (open);
}

int	check_input(char *input)
{
	if (open_quotes(input))
		return (!ft_error(2));
	if (invalid_char(input, ';'))
		return (!invalid_token_error("';'"));
	if (invalid_char(input, '&'))
		return (!invalid_token_error("'&'"));
	if (invalid_char(input, '\\'))
		return (!invalid_token_error("'\\'"));
	return (1);
}
