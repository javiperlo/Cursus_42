# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 12:05:06 by javperez          #+#    #+#              #
#    Updated: 2024/05/06 19:15:44 by javperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colores
END=\e[0m
GREEN=\e[1;32m
CYAN=\e[1;36m
WHITE=\e[1;37m
NAME = minishell
FLAGS = -Wall -Wextra -Werror -g3

# Compilador
CC = cc

# Directorios de Compilación
LIBFTP = libft/
PATHB = build/
PATHO = build/objs/
PATHS = sources/
PATHSL = sources/lexer/
PATHSP = sources/parser/
PATHSB = sources/builtins/
PATHSU = sources/utils/
PATHSE = sources/error/
PATHP = sources/pipex/
PATHEX = sources/executor/

BUILD_PATHS = $(PATHB) $(PATHO)

# Archivos
sources	=	sources/main.c \
			sources/signal.c \
			sources/builtins/builtins.c \
			sources/builtins/m_cd.c \
			sources/builtins/m_echo.c \
			sources/builtins/m_env.c \
			sources/builtins/m_exit.c \
			sources/builtins/m_export.c \
			sources/builtins/m_pwd.c \
			sources/builtins/m_unset.c \
			sources/builtins/utils_builtins.c \
			sources/builtins/p_builtins.c \
			sources/utils/parse_envp.c \
			sources/utils/utils.c \
			sources/error/error_handling.c \
			sources/executor/redirection_check.c \
			sources/executor/executor.c \
			sources/executor/cmds_handler.c \
			sources/executor/exec_utils.c \
			sources/executor/heredoc.c \
			sources/executor/executor_utils.c \
			sources/lexer/input_validation.c \
			sources/lexer/lexer.c \
			sources/lexer/lexer_utils.c \
			sources/lexer/lexer_validation.c \
			sources/lexer/symbol_utils.c \
			sources/lexer/expand_env.c \
			sources/lexer/combine_quotes.c \
			sources/parser/parser.c \
			sources/parser/parser_utils.c \
			sources/parser/redirections.c \
			sources/parser/tokens.c

OBJS	=	$(addprefix $(PATHO), $(notdir $(patsubst %.c, %.o, $(sources))))

LIBFT	=	./libft/libft.a

HEADER	=	.includes/builtins.h \
			.includes/error.h \
			.includes/executor.h \
			.includes/minishell.h \
			.includes/parsing.h \
			.includes/lexer.h \
			.includes/utils.h

#READLINE_DIR = $(shell brew --prefix readline)

READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib -lreadline -L$(LIBFTP) -lft
# READLINE_LIB = -lreadline -lhistory -lreadline -Llibft/ -lft

INCLUDES = -I./includes -I$(PATHP) -I$(LIBFTP) -I$(READLINE_DIR)/include

all: $(BUILD_PATHS) $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(BUILD_PATHS)
	@$(CC) $(FLAGS) $(LIBFT) $(OBJS) $(READLINE_LIB) -o $(NAME)

$(PATHO)%.o:: $(PATHSP)%.c $(HEADERS)
	@echo "$(WHITE)Compiling - $(WHITE)${notdir $<}$(END)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHS)%.c $(HEADERS)
	@echo "$(WHITE)Compiling - $(WHITE)${notdir $<}$(END)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSL)%.c $(HEADERS)
	@echo "$(WHITE)Compiling - $(WHITE)${notdir $<}$(END)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSB)%.c $(HEADERS)
	@echo "$(WHITE)Compiling - $(WHITE)${notdir $<}$(END)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSU)%.c $(HEADERS)
	@echo "$(WHITE)Compiling - $(WHITE)${notdir $<}$(END)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSE)%.c $(HEADERS)
	@echo "$(WHITE)Compiling - $(WHITE)${notdir $<}$(END)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHEX)%.c $(HEADERS)
	@echo "$(WHITE)Compiling - $(WHITE)${notdir $<}$(END)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFTP)

$(PATHB):
	@mkdir $(PATHB)

$(PATHO):
	@mkdir $(PATHO)

clean:
	@echo "Cleaning"
	@rm -f $(OBJS)
	@rm -f .tmp*
	@rm -rf $(PATHO) $(PATHB)
	@make fclean -C $(LIBFTP)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PRECIOUS: $(PATHO)%.o
