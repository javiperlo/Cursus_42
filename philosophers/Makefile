# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 12:16:03 by javperez          #+#    #+#              #
#    Updated: 2024/09/13 20:03:24 by javperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -pthread #-fsanitize=thread
RM		=	rm -f

SRCS	=	src/main.c \
			src/utils.c \
			src/checker_philos.c \
			src/init.c \
			src/philo_actions.c \
			src/threads.c

OBJS	=	$(SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJS)
			
fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
