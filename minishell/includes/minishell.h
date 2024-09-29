/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:48:49 by javperez          #+#    #+#             */
/*   Updated: 2024/05/07 15:49:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include "utils.h"
# include "error.h"
# include "builtins.h"
# include "executor.h"
# include "parsing.h"
# include <sys/types.h>
# include <sys/wait.h>

# define WELCOME_MSG "hello"
# define HEREDOC_MSG	"\033[1;34m> \033[0m"
# define READLINE_MSG	"\e[1;96mminishell\033[34m> \033[0m"

extern int		g_status_code;

int		find_pwd(t_utils *utils);
int		reset_utils(t_utils *utils);
void	sigint_handler(int sig);
void	sigquit_handler(int sig);
void	init_signals(void);
char	**add_var(char **arr, char *str);

char	*delete_quotes_value(char *str);

int		parse_paths(t_utils *utils);

typedef enum e_status
{
	IN_CMD = 20,
	IN_HEREDOC = 40,
	CTRL_C = 130,
	CTRL_BS = 131,
	STOP_HEREDOC = 1,
}	t_g_status_code;

#endif
