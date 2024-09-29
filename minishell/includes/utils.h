/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:49:10 by javperez          #+#    #+#             */
/*   Updated: 2024/05/07 15:46:18 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "parsing.h"
# include "minishell.h"

// utils
int		implement_utils(t_utils *utils);
char	**ft_arrdup(char **arr);

void	free_utils(t_utils *utils);
void	init_utils(t_utils *utils, char **envp);

#endif
