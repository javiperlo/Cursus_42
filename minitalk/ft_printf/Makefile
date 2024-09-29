# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 18:44:17 by javperez          #+#    #+#              #
#    Updated: 2023/11/10 18:54:30 by javperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

PRINTF_SRCS	= ft_printf.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putdigits.c \
				ft_putdigits.c \
				ft_putpointer.c

OBJS		= $(PRINTF_SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
				$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
			@$(RM) $(OBJS)

fclean:		
			@$(RM) $(NAME)	$(OBJS)

re:			fclean all

.PHONY:		all clean fclean re