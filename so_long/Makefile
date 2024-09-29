# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 18:12:20 by javperez          #+#    #+#              #
#    Updated: 2024/03/13 19:06:41 by javperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS = --silent

# Definición de colores
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[0;34m
CYAN=\033[0;36m
WHITE=\033[1;37m
WHITE_LOW=\033[0;37m
DEF_COLOR=\033[0m

CFLAGS = -Wall -Werror -Wextra -w -g -fsanitize=address

HEADERS =	include/so_long.h \
			get_next_line/get_next_line.h \

NAME = so_long

SRCS = 	sources/so_long.c \
		sources/ft_check_map.c \
		sources/ft_checker_posible.c \
		sources/ft_malloc_map.c \
		sources/ft_movement.c \
		sources/ft_utils.c \
		sources/ft_finish.c \
		sources/ft_draw_map.c \
		get_next_line/get_next_line_utils.c\
		get_next_line/get_next_line.c

OBJS = $(SRCS:.c=.o)

all: intro $(NAME)

intro:
	@echo 
	@echo "$(WHITE)███████╗ ██████╗     ██╗      ██████╗ ███╗   ██╗ ██████╗ $(DEF_COLOR)"
	@echo "$(WHITE)██╔════╝██╔═══██╗    ██║     ██╔═══██╗████╗  ██║██╔════╝ $(DEF_COLOR)"
	@echo "$(WHITE)███████╗██║   ██║    ██║     ██║   ██║██╔██╗ ██║██║  ███╗$(DEF_COLOR)"
	@echo "$(WHITE)╚════██║██║   ██║    ██║     ██║   ██║██║╚██╗██║██║   ██║$(DEF_COLOR)"
	@echo "$(WHITE)███████║╚██████╔╝    ███████╗╚██████╔╝██║ ╚████║╚██████╔╝$(DEF_COLOR)"
	@echo "$(WHITE)╚══════╝ ╚═════╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ $(DEF_COLOR)"
	@printf "$(WHITE)Compilando $(NAME)...$(DEF_COLOR)"

$(NAME) : $(OBJS) $(HEADERS)
	@gcc $(OBJS) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(WHITE)\n\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n$(DEF_COLOR)"
	@echo "$(GREEN)✅ Compilación realizada con éxito\n$(DEF_COLOR)"

clean:
	@echo
	@echo "$(RED)🗑  Limpiando archivos ...$(DEF_COLOR)"
	@rm -rf $(OBJS)
	@echo
	@sleep 0.2
	@echo "$(GREEN)✅ Archivos borrados con éxito$(DEF_COLOR)"
	@echo

fclean:	clean
	@rm -rf $(NAME)

re: fclean all