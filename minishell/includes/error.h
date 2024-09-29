/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:48:24 by javperez          #+#    #+#             */
/*   Updated: 2024/05/07 15:44:58 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "minishell.h"
# include "parsing.h"

int		parser_error(t_word *ptr);
int		invalid_token_error(char *c);
int		token_error(t_utils *utils, int code);

//ft_error
int		ft_error(int error);

typedef enum e_err_code
{
	ERR_SEMICOL,
	ERR_BACKSLASH,
	ERR_QUOTES,
	ERR_PIPE,
	ERR_G,
	ERR_GG,
	ERR_L,
	ERR_LL,
	ERR_NL,
}	t_err_code;

#endif
