/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:48:15 by javperez          #+#    #+#             */
/*   Updated: 2024/05/07 15:49:43 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include <dirent.h>
# include "minishell.h"
# include "parsing.h"

//builtins
int		(*builtin_arr(char *str))(t_utils *utils, t_cmds *cmds);
int		m_echo(t_utils *utils, t_cmds *cmds);
int		m_cd(t_utils *utils, t_cmds *cmds);
int		m_pwd(t_utils *utils, t_cmds *cmds);
int		m_export(t_utils *utils, t_cmds *cmds);
int		m_unset(t_utils *utils, t_cmds *cmds);
int		m_env(t_utils *utils, t_cmds *cmds);
int		m_exit(t_utils *utils, t_cmds *cmds);

void	sorted_env(t_utils *utils);
size_t	equal_sign(char *str);
int		invalid_identifier(char *str, int f);
void	change_path(t_utils *utils);
void	update_path_to_env(t_utils *utils);
int		check_valid_identifier(char c);
int		error_invalid_identifier(char *identifier);
char	**del_var(char **arr, char *str);
char	**add_var(char **arr, char *str);
int		check_parameter(char *str);
int		variable_exist(t_utils *utils, char *str);
int		is_str_digit(char *str);
int		p_specific_path(t_utils *utils, char *str);
char	*find_path_ret(char *str, t_utils *utils);
void	p_builtins(t_utils *utils, t_cmds *cmd);

#endif
