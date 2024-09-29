/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:46:56 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:21:54 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	determine_exit_code(char **str)
{
	int	exit_code;

	if (!str[1])
		exit_code = 0;
	else if (is_str_digit(str[1]))
		exit_code = ft_atoi(str[1]);
	else
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit_code = 255;
	}
	free_double_ptr((void **) str);
	exit(exit_code);
}

int	m_exit(t_utils *utils, t_cmds *cmds)
{
	char	**str;

	if (utils->pipes == 0)
		ft_putendl_fd("exit", STDERR_FILENO);
	if (cmds->args[1] && cmds->args[2] && is_str_digit(cmds->args[1]))
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else if (cmds->args[1] && !is_str_digit(cmds->args[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(cmds->args[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		reset_utils(utils);
		free_utils(utils);
		exit(255);
	}
	str = ft_arrdup(cmds->args);
	reset_utils(utils);
	free_utils(utils);
	determine_exit_code(str);
	return (EXIT_SUCCESS);
}
