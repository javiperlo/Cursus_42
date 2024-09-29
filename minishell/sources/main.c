/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:33:47 by javperez          #+#    #+#             */
/*   Updated: 2024/05/09 19:35:57 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell_loop(t_utils *utils)
{
	while (1)
	{
		utils->input = readline(READLINE_MSG);
		implement_utils(utils);
		if (!utils->input)
		{
			reset_utils(utils);
			free_utils(utils);
			printf("exit\n");
			exit(EXIT_SUCCESS);
		}
		else if (utils->input[0] == '\0')
		{
			reset_utils(utils);
			continue ;
		}
		add_history(utils->input);
		if (parse_input(utils))
			preparing_executor(utils);
		reset_utils(utils);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_utils	utils;

	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	init_signals();
	init_utils(&utils, envp);
	minishell_loop(&utils);
	free_utils(&utils);
	return (0);
}
