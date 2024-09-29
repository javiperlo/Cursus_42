/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:34:50 by javperez          #+#    #+#             */
/*   Updated: 2024/05/08 17:59:01 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_pwd(t_utils *utils)
{
	char	**tmp;
	char	*var;

	if (!utils->envp)
		utils->envp = (char **) ft_calloc(2, sizeof(char *));
	if (!utils->pwd || !utils->old_pwd)
	{
		utils->pwd = getcwd(NULL, 0);
		utils->old_pwd = NULL;
		tmp = utils->envp;
		var = ft_strjoin("PWD=", utils->pwd);
		utils->envp = add_var(utils->envp, var);
		free_double_ptr((void **) tmp);
		free(var);
		var = ft_strjoin("OLDPWD=", utils->old_pwd);
		tmp = utils->envp;
		utils->envp = add_var(utils->envp, var);
		free_double_ptr((void **) tmp);
		free(var);
	}
}

int	find_pwd(t_utils *utils)
{
	int	i;

	i = 0;
	utils->pwd = 0;
	utils->old_pwd = 0;
	while (utils->envp && utils->envp[i])
	{
		if (!ft_strncmp(utils->envp[i], "PWD=", 4))
			utils->pwd = ft_substr(utils->envp[i],
					4, ft_strlen(utils->envp[i]) - 4);
		else if (!ft_strncmp(utils->envp[i], "OLDPWD=", 7))
			utils->old_pwd = ft_substr(utils->envp[i],
					7, ft_strlen(utils->envp[i]) - 7);
		i++;
	}
	check_pwd(utils);
	return (1);
}

char	*find_path(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
		i++;
	}
	return (ft_strdup("\0"));
}

int	parse_paths(t_utils *utils)
{
	char	*path_from_envp;
	int		i;
	char	*tmp;

	path_from_envp = find_path(utils->envp);
	utils->paths = ft_split(path_from_envp, ':');
	free(path_from_envp);
	i = 0;
	while (utils->paths[i])
	{
		if (ft_strncmp(&utils->paths[i][ft_strlen(utils->paths[i]) - 1],
			"/", 1) != 0)
		{
			tmp = ft_strjoin(utils->paths[i], "/");
			free(utils->paths[i]);
			utils->paths[i] = tmp;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

void	init_utils(t_utils *utils, char **envp)
{
	utils->cmds = 0;
	utils->paths = 0;
	utils->pwd = 0;
	utils->old_pwd = 0;
	utils->pipes = 0;
	utils->pid = 0;
	utils->envp = 0;
	utils->reset = false;
	if (*envp != 0)
		utils->envp = ft_arrdup(envp);
	find_pwd(utils);
}
