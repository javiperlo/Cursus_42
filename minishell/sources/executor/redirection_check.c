/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:44:37 by agomez-m          #+#    #+#             */
/*   Updated: 2024/05/06 19:32:55 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_append_outfile(t_redir *redir)
{
	int	fd;

	if (redir->type == APPEND)
		fd = open(redir->path,
				O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(redir->path,
				O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

int	handle_infile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: infile: No such file or directory\n",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0 && dup2(fd, STDIN_FILENO) < 0)
	{
		ft_putstr_fd("minishell: pipe error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0)
		close(fd);
	return (EXIT_SUCCESS);
}

int	handle_open(t_redir *redir)
{
	int	fd;

	fd = open(redir->path, O_CREAT, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: outfile: Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0)
		close(fd);
	return (EXIT_SUCCESS);
}

int	handle_outfile(t_redir *redir)
{
	int	fd;

	fd = check_append_outfile(redir);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: outfile: Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0 && dup2(fd, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd("minishell: pipe error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0)
		close(fd);
	return (EXIT_SUCCESS);
}

int	check_redirections(t_cmds *cmd)
{
	t_redir	*redir;

	redir = cmd->redirections;
	while (redir)
	{
		if (redir->type == INPUT)
		{
			if (handle_infile(redir->path))
				return (EXIT_FAILURE);
		}
		else if (redir->type == HEREDOC)
			if (handle_infile(cmd->hd_file_name))
				return (EXIT_FAILURE);
		if (check_redir_helper(redir->type, redir) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}
