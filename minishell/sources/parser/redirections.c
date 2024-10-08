/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:37:16 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:21:54 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	last_in_redir(t_cmds *cmd)
{
	t_redir	*ptr;
	t_redir	*last;
	int		type;

	if (!cmd->redirections)
		return ;
	type = -1;
	ptr = cmd->redirections;
	while (ptr)
	{
		if (ptr->type == INPUT)
		{
			type = ptr->type;
			ptr->type = IGNORE;
			last = ptr;
		}
		ptr = ptr->next;
	}
	if (type != -1)
		last->type = type;
}

void	last_out_redir(t_cmds *cmd)
{
	t_redir	*ptr;
	t_redir	*last;
	int		type;

	if (!cmd->redirections)
		return ;
	type = -1;
	ptr = cmd->redirections;
	while (ptr)
	{
		if (ptr->type == WRITE || ptr->type == APPEND)
		{
			type = ptr->type;
			ptr->type = OPEN;
			last = ptr;
		}
		ptr = ptr->next;
	}
	if (type != -1)
		last->type = type;
}

void	sort_redir(t_word *ptr, t_redir *redir)
{
	if (ptr->cont[0] == '<' && !ptr->cont[1])
		redir->type = INPUT;
	else if (ptr->cont[0] == '>' && !ptr->cont[1])
		redir->type = WRITE;
	else if (ptr->cont[0] == '<' && ptr->cont[1] == '<')
		redir->type = HEREDOC;
	else if (ptr->cont[0] == '>' && ptr->cont[1] == '>')
		redir->type = APPEND;
}

t_cmds	*push_redir(t_cmds *cmd, t_word *ptr)
{
	t_redir	*r;
	t_redir	*redir;

	redir = (t_redir *)ft_calloc(1, sizeof(t_redir));
	if (!redir)
	{
		ft_error(1);
		return (0);
	}
	if (ptr->next->type == PATH)
		redir->path = ft_strdup(ptr->next->cont);
	else
		return (0);
	sort_redir(ptr, redir);
	r = cmd->redirections;
	if (!r)
		cmd->redirections = redir;
	else
	{
		while (r->next)
			r = r->next;
		r->next = redir;
	}
	redir->prev = r;
	return (cmd);
}
