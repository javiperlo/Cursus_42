/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:43:28 by agomez-m          #+#    #+#             */
/*   Updated: 2024/05/06 19:41:13 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*join_split_str(char **split_str, char *new_str)
{
	char	*tmp;
	char	*add_space;
	int		i;

	tmp = ft_strdup(split_str[0]);
	i = 1;
	while (split_str[i])
	{
		new_str = tmp;
		add_space = ft_strjoin(new_str, " ");
		free(new_str);
		tmp = ft_strjoin(add_space, split_str[i]);
		free(add_space);
		i++;
	}
	new_str = tmp;
	return (new_str);
}

int	check_redir_helper(int type, t_redir *dir)
{
	int	fd;

	if (type == OPEN)
	{
		if (handle_open(dir))
			return (EXIT_FAILURE);
	}
	else if (type == WRITE || type == APPEND)
	{
		if (handle_outfile(dir))
			return (EXIT_FAILURE);
	}
	else if (type == IGNORE)
	{
		fd = open(dir->path, O_RDONLY);
		if (fd < 0)
		{
			ft_putstr_fd("minishell: infile: No such file or directory\n",
				STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		close (fd);
	}
	return (EXIT_SUCCESS);
}

int	exec_error(char *str, int code)
{
	write(STDERR_FILENO, "minishell: ", 12);
	write(STDERR_FILENO, str, ft_strlen(str));
	if (code == 0)
		write(STDERR_FILENO, ": command not found\n", 21);
	else if (code == 1)
		write(STDERR_FILENO, ": No such file or directory\n", 29);
	else if (code == 2)
		write(STDERR_FILENO, ": Not a directory\n", 19);
	else if (code == 3)
		write(STDERR_FILENO, ": is a directory\n", 18);
	else if (code == 4)
		write(STDERR_FILENO, ": Permission denied\n", 21);
	if (code == 1 || code == 0)
		return (127);
	return (126);
}

int	loop_paths(t_utils *utils, t_cmds *cmd)
{
	int		i;
	char	*mycmd;

	i = 0;
	if (cmd->command[0] != '/' && cmd->command[0] != '.')
	{
		while (utils->paths && utils->paths[i])
		{
			mycmd = ft_strjoin(utils->paths[i], cmd->command);
			if (!access(mycmd, F_OK))
			{
				execve(mycmd, cmd->args, utils->envp);
				return (find_exec_error(mycmd, 1));
			}
			free(mycmd);
			i++;
		}
	}
	return (0);
}

int	is_directory(char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (!dir)
		return (0);
	else
	{
		closedir(dir);
		return (1);
	}
}
