/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:46:03 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:21:54 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_path_ret(char *str, t_utils *utils)
{
	int	i;

	i = 0;
	while (utils->envp && utils->envp[i])
	{
		if (!ft_strncmp(utils->envp[i], str, ft_strlen(str)))
			return (ft_substr(utils->envp[i], ft_strlen(str),
					ft_strlen(utils->envp[i]) - ft_strlen(str)));
		i++;
	}
	return (NULL);
}

int	specific_path(t_utils *utils, char *str)
{
	char	*tmp;
	int		ret;

	ret = -1;
	tmp = find_path_ret(str, utils);
	if (tmp)
	{
		ret = chdir(tmp);
		free(tmp);
	}
	if (ret != 0)
	{
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		ft_putstr_fd(str, STDERR_FILENO);
		free(str);
		ft_putendl_fd(" not set", STDERR_FILENO);
	}
	return (ret);
}

void	update_path_to_env(t_utils *utils)
{
	int		i;
	char	*tmp;

	i = 0;
	while (utils->envp && utils->envp[i])
	{
		if (!ft_strncmp(utils->envp[i], "PWD=", 4))
		{
			tmp = ft_strjoin("PWD=", utils->pwd);
			free(utils->envp[i]);
			utils->envp[i] = tmp;
		}
		else if (!ft_strncmp(utils->envp[i], "OLDPWD=", 7) && utils->old_pwd)
		{
			tmp = ft_strjoin("OLDPWD=", utils->old_pwd);
			free(utils->envp[i]);
			utils->envp[i] = tmp;
		}
		i++;
	}
}

int	cd_helper(t_utils *utils, t_cmds *cmds)
{
	char	*tmp;
	char	*tmp1;
	char	*tmp2;
	int		ret;

	if (cmds->args[1][0] == '~')
	{
		tmp = find_path_ret("HOME=", utils);
		tmp1 = ft_substr(cmds->args[1], 1, ft_strlen(cmds->args[1]) - 1);
		tmp2 = ft_strjoin(tmp, tmp1);
		ret = chdir(tmp2);
		free(tmp);
		free(tmp1);
		free(tmp2);
	}
	else
		ret = chdir(cmds->args[1]);
	if (ret != 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmds->args[1], STDERR_FILENO);
		perror(" ");
	}
	return (ret);
}

int	m_cd(t_utils *utils, t_cmds *cmds)
{
	int	ret;

	if (!cmds->args[1])
		ret = specific_path(utils, "HOME=");
	else if (ft_strncmp(cmds->args[1], "-", 1) == 0)
		ret = specific_path(utils, "OLDPWD=");
	else
		ret = cd_helper(utils, cmds);
	if (ret != 0)
		return (EXIT_FAILURE);
	change_path(utils);
	update_path_to_env(utils);
	return (EXIT_SUCCESS);
}
