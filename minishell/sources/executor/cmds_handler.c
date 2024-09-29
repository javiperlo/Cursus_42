/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:42:43 by agomez-m          #+#    #+#             */
/*   Updated: 2024/05/06 19:44:19 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_exec_error(char *cmd, int code)
{
	char	*temp;

	if (code == 1 && !access(cmd, X_OK))
	{
		exec_error(cmd, 4);
		free(cmd);
		return (126);
	}
	if (code == 2)
	{
		temp = ft_substr(cmd, 0, ft_strlen(cmd) - 2);
		if (cmd[ft_strlen(cmd) - 1] == '/'
			&& access(temp, F_OK))
		{
			free (temp);
			return (exec_error(cmd, 2));
		}
		free (temp);
		if (cmd[ft_strlen(cmd) - 1] == '/'
			&& access(cmd, F_OK))
			return (exec_error(cmd, 1));
	}
	return (exec_error(cmd, 0));
}

int	find_cmd(t_cmds *cmd, t_utils *utils)
{
	if (ft_strlen(cmd->command) == 0)
		return (exec_error(cmd->command, 0));
	if (is_directory(cmd->command))
		return (exec_error(cmd->command, 3));
	else if (cmd->command[ft_strlen(cmd->command) - 1] == '/')
		return (find_cmd_helper(cmd));
	if (cmd->command[0] != '/' && cmd->command[0] != '.')
	{
		if (loop_paths(utils, cmd) != 0)
			return (127);
	}
	else if (!access(cmd->command, F_OK) && (cmd->command[0] == '/'
			|| cmd->command[0] == '.'))
	{
		if (access(cmd->command, X_OK))
			return (exec_error(cmd->command, 4));
		execve(cmd->command, cmd->args, utils->envp);
	}
	else if (access(cmd->command, F_OK))
		return (find_exec_error(cmd->command, 1));
	return (find_exec_error(cmd->command, 0));
}

void	handle_cmd(t_cmds *cmd, t_utils *utils)
{
	int	exit_code;

	exit_code = 0;
	if (cmd->redirections && check_redirections(cmd))
	{
		reset_utils(utils);
		free_utils(utils);
		exit(1);
	}
	if (cmd->builtin != NULL)
	{
		exit_code = cmd->builtin(utils, cmd);
		reset_utils(utils);
		free_utils(utils);
		exit(exit_code);
	}
	else if (cmd->command)
		exit_code = find_cmd(cmd, utils);
	reset_utils(utils);
	free_utils(utils);
	exit(exit_code);
}

void	dup_cmd(t_cmds *cmd, t_utils *utils, int end[2], int fd_in)
{
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		ft_error(4);
	close(end[0]);
	if (cmd->next && dup2(end[1], STDOUT_FILENO) < 0)
		ft_error(4);
	close(end[1]);
	if (cmd->prev)
		close(fd_in);
	handle_cmd(cmd, utils);
}

void	one_cmd(t_cmds *cmd, t_utils *utils)
{
	int	pid;
	int	status;
	int	exit_status;

	exit_status = -1;
	if (send_heredoc(utils, cmd) == EXIT_FAILURE)
		return ;
	pid = fork();
	if (pid < 0)
		ft_error(5);
	else if (pid == 0)
		handle_cmd(cmd, utils);
	if (cmd->builtin == m_export || cmd->builtin == m_cd
		|| cmd->builtin == m_exit || cmd->builtin == m_unset)
		p_builtins(utils, cmd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	if (g_status_code != STOP_HEREDOC && exit_status != -1)
		g_status_code = exit_status;
}
