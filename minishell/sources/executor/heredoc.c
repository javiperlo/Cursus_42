/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:40:10 by agomez-m          #+#    #+#             */
/*   Updated: 2024/05/06 19:40:19 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	display_error(int errorCode)
{
	ft_error(errorCode);
	return (EXIT_FAILURE);
}

int	create_heredoc(t_redir *heredoc, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		close(fd);
		return (display_error(7));
	}
	line = readline(HEREDOC_MSG);
	while (line && (ft_strcmp(heredoc->path, line)
			&& g_status_code != STOP_HEREDOC))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline(HEREDOC_MSG);
	}
	close(fd);
	free(line);
	if (g_status_code == STOP_HEREDOC)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_heredoc(t_utils *utils, t_redir *heredoc, char *file_name)
{
	int		sl;

	sl = EXIT_SUCCESS;
	g_status_code = IN_HEREDOC;
	sl = create_heredoc(heredoc, file_name);
	g_status_code = sl;
	if (sl == EXIT_SUCCESS)
		utils->heredoc = true;
	return (sl);
}

char	*generate_heredoc_filename(void)
{
	static int	i = 0;
	char		*num;
	char		*file_name;

	num = ft_itoa(i++);
	file_name = ft_strjoin(".tmp_heredoc_file_", num);
	free(num);
	return (file_name);
}

int	send_heredoc(t_utils *utils, t_cmds *cmd)
{
	t_redir	*redir;
	int		sl;

	redir = cmd->redirections;
	sl = EXIT_SUCCESS;
	while (redir)
	{
		if (redir->type == HEREDOC)
		{
			if (cmd->hd_file_name)
				free (cmd->hd_file_name);
			cmd->hd_file_name = generate_heredoc_filename();
			sl = ft_heredoc(utils, redir, cmd->hd_file_name);
			if (sl)
				return (EXIT_FAILURE);
		}
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}
