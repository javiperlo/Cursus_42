/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:35:39 by javperez          #+#    #+#             */
/*   Updated: 2024/05/09 21:12:47 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_word	*init_cmd(t_word *start, t_cmds *new_cmd)
{
	t_word	*ptr;

	ptr = start;
	while (ptr && ptr->type != PIPE)
	{
		if (ptr->type == CMD)
			new_cmd->command = ft_strdup(ptr->cont);
		else if (ptr->type == REDIR)
			new_cmd = push_redir(new_cmd, ptr);
		ptr = ptr->next;
	}
	new_cmd->args = init_args(start, new_cmd->command);
	if (!new_cmd->command)
		new_cmd->command = new_cmd->args[0];
	else
		new_cmd->args[0] = new_cmd->command;
	return (ptr);
}

char	**init_args(t_word *start, char *command)
{
	t_word	*ptr;
	int		count;
	char	**args;

	count = count_args(start, command);
	args = (char **)ft_calloc(count + 2, sizeof(char *));
	if (!args)
		ft_error(1);
	count = 1;
	if (!command)
	{
		count = 0;
	}
	ptr = start;
	while (args && ptr && ptr->type != PIPE)
	{
		if (ptr->type == ARG)
		{
			args[count++] = ft_strdup(ptr->cont);
		}
		ptr = ptr->next;
	}
	return (args);
}

void	push_cmd(t_utils *utils, t_cmds *cmd)
{
	t_cmds	*ptr;

	cmd->builtin = builtin_arr(cmd->command);
	last_in_redir(cmd);
	last_out_redir(cmd);
	ptr = utils->cmds;
	if (!ptr)
		utils->cmds = cmd;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = cmd;
		cmd->prev = ptr;
	}
}

char	*ft_getenv(char *var, t_utils *utils)
{
	int		i;
	char	**value;
	char	*ret;

	i = -1;
	while (utils->envp[++i])
	{
		value = ft_split(utils->envp[i], '=');
		if (!value)
		{
			ft_error(1);
			return (0);
		}
		if (!ft_strcmp(var, value[0]))
		{
			if (value[1])
				ret = ft_strdup(value[1]);
			else
				ret = ft_calloc(1, sizeof(char));
			free_double_ptr((void **) value);
			return (ret);
		}
		free_double_ptr((void **) value);
	}
	return (ft_strdup(""));
}

char	*expand_err(char *cont, int *i)
{
	char	*err;

	err = ft_itoa(g_status_code);
	(*i) = (*i) + 2;
	cont = replace_env(cont, i, err, 1);
	if (!cont)
		return (0);
	(*i) = 0;
	return (cont);
}
