# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 20:54:57 by javperez          #+#    #+#              #
#    Updated: 2023/10/04 12:04:57 by javperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs #El comando AR crea una libreria y RCS es para que no muestre mensajes
RM = rm -f #El comando RM elimina archivos

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
SRC = ft_isalnum.c ft_isascii.c ft_strlcat.c ft_atoi.c\
	ft_isprint.c ft_memcmp.c ft_memset.c ft_strlen.c\
	ft_strnstr.c ft_tolower.c ft_bzero.c ft_isalpha.c\
	ft_isdigit.c ft_memchr.c ft_memcpy.c ft_strchr.c ft_strlcpy.c\
	ft_strncmp.c ft_strrchr.c ft_toupper.c ft_memmove.c ft_strdup.c\
	ft_itoa.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strdup.c\
	ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_split.c ft_striteri.c ft_strmapi.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstsize.c ft_lstlast.c ft_lstmap.c\

NAME = libft.a
INCLUDE = libft.h
OBJ = $(SRC:.c=.o) #Crea los archivos .o
OBJ_BONUS = $(BONUS:.c=.o)

#No es estrictamente necesario, pero si se pone, se ejecuta el comando make
all: $(NAME) #Crea el ejecutable

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	$(LIB) $(NAME) $(OBJ) $(OBJ_BONUS)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean: #Borra los archivos .o
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean #Borra los archivos .o y el ejecutable
	$(RM) $(NAME)

re: fclean all #Borra los archivos .o, el ejecutable y lo vuelve a crear

.PHONY: clean fclean re bonus