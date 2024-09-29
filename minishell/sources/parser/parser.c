/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:36:22 by javperez          #+#    #+#             */
/*   Updated: 2024/05/09 19:41:17 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	sort_tokens(t_split *split, t_utils *utils)
{
	t_word	*ptr;
	t_cmds	*new_cmd;

	ptr = split->first;
	while (ptr)
	{
		new_cmd = (t_cmds *)ft_calloc(1, sizeof(t_cmds));
		if (!new_cmd)
			return (!ft_error(1));
		ptr = init_cmd(ptr, new_cmd);
		if (!new_cmd || !new_cmd->args)
			return (0);
		push_cmd(utils, new_cmd);
		if (ptr && ((ptr->type == PIPE)))
			ptr = ptr->next;
	}
	return (1);
}

int	count_pipes(t_utils *utils)
{
	t_cmds	*ptr;
	int		count;

	count = 0;
	ptr = utils->cmds;
	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	return (count - 1);
}

int	parse_input(t_utils *utils)
{
	t_split	*split;
	int		sorted;

	if (!check_input(utils->input))
		return (0);
	split = split_input(utils->input, utils);
	if (!split)
		return (0);
	sorted = sort_tokens(split, utils);
	free_split(split);
	utils->pipes = count_pipes(utils);
	return (sorted);
}

int	count_args(t_word *start, char *command)
{
	t_word	*ptr;
	int		count;

	ptr = start;
	count = 0;
	while (ptr && ptr->type != PIPE)
	{
		if (ptr->type == ARG)
			count ++;
		ptr = ptr->next;
	}
	if (!command)
		count --;
	return (count);
}
