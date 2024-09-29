/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:41:24 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:21:54 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_split(t_split *split)
{
	t_word	*ptr;

	ptr = split->first;
	if (ptr && ptr->type == PIPE)
		return (!parser_error(ptr));
	if (ptr && (split->last->type == PIPE || split->last->type == REDIR))
		return (!ft_error(0));
	while (ptr)
	{
		if (ptr->type == REDIR && (ptr->next && (ptr->next->type == REDIR
					|| ptr->next->type == PIPE)))
			return (!parser_error(ptr));
		if (ptr->type == PIPE && (ptr->next && ptr->next->type == PIPE))
			return (!parser_error(ptr));
		ptr = ptr->next;
	}
	return (1);
}
