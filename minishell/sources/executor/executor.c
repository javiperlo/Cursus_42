/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:43:48 by agomez-m          #+#    #+#             */
/*   Updated: 2024/05/06 19:44:19 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pipe_wait(int *pid, int amount)
{
	int	i;
	int	status;
	int	exit_status;

	i = 0;
	status = 0;
	while (i < amount)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	waitpid(pid[i], &status, 0);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	if (g_status_code != STOP_HEREDOC)
		g_status_code = exit_status;
	return (EXIT_SUCCESS);
}

int	ft_fork(t_utils *utils, int end[2], int fd_in, t_cmds *cmd)
{
	static int	i = 0;

	if (utils->reset == true)
	{
		i = 0;
		utils->reset = false;
	}
	utils->pid[i] = fork();
	if (utils->pid[i] < 0)
		ft_error(5);
	if (utils->pid[i] == 0)
		dup_cmd(cmd, utils, end, fd_in);
	i++;
	return (EXIT_SUCCESS);
}

int	check_fd_heredoc(t_utils *utils, int end[2], t_cmds *cmd)
{
	int	fd_in;

	if (utils->heredoc)
	{
		close(end[0]);
		fd_in = open(cmd->hd_file_name, O_RDONLY);
	}
	else
		fd_in = end[0];
	return (fd_in);
}

int	executor(t_utils *utils)
{
	int		end[2];
	int		fd_in;
	t_cmds	*curr_cmd;

	fd_in = STDIN_FILENO;
	curr_cmd = utils->cmds;
	while (curr_cmd)
	{
		if (curr_cmd->next)
			if (pipe(end) < 0)
				return (!ft_error(4));
		send_heredoc(utils, curr_cmd);
		if (ft_fork(utils, end, fd_in, curr_cmd) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		close(end[1]);
		if (curr_cmd->prev)
			close(fd_in);
		fd_in = check_fd_heredoc(utils, end, curr_cmd);
		if (curr_cmd->next)
			curr_cmd = curr_cmd->next;
		else
			break ;
	}
	pipe_wait(utils->pid, utils->pipes);
	return (0);
}

int	preparing_executor(t_utils *utils)
{
	signal(SIGQUIT, sigquit_handler);
	g_status_code = IN_CMD;
	if (utils->pipes == 0)
		one_cmd(utils->cmds, utils);
	else
	{
		utils->pid = ft_calloc(utils->pipes + 2, sizeof(int));
		if (!utils->pid)
			return (ft_error(1));
		if (executor(utils))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
