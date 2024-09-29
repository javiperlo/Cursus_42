/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:43:16 by agomez-m          #+#    #+#             */
/*   Updated: 2024/05/06 19:32:14 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_cmd_helper(t_cmds *cmd)
{
	char	*tmp;
	char	*tmp1;

	tmp1 = ft_strtrim(cmd->command, "/");
	if (cmd->command[0] == '/')
		tmp = ft_strjoin("/", tmp1);
	else
		tmp = ft_strdup(tmp1);
	free(tmp1);
	if (!access(tmp, F_OK))
	{
		free(tmp);
		return (exec_error(cmd->command, 2));
	}
	else
	{
		free(tmp);
		return (exec_error(cmd->command, 1));
	}
}
