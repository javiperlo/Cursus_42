/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:45:27 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:21:54 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	(*builtin_arr(char *str))(t_utils *utils, t_cmds *cmds)
{
	static void	*builtins[7][2] = {
	{"echo", m_echo},
	{"cd", m_cd},
	{"pwd", m_pwd},
	{"export", m_export},
	{"unset", m_unset},
	{"env", m_env},
	{"exit", m_exit}
	};
	int			i;

	i = 0;
	while (str && i < 7)
	{
		if (!ft_strncmp(builtins[i][0], str, ft_strlen((builtins[i][0])))
			&& !ft_strncmp(builtins[i][0], str, ft_strlen(str)))
			return (builtins[i][1]);
		i++;
	}
	return (NULL);
}

int	p_specific_path(t_utils *utils, char *str)
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
	return (ret);
}
