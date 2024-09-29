CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME_CLIENT = client
NAME_SERVER = server
PRINTF = ./ft_printf/libftprintf.a

SRC_CLIENT = srcs/client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SRC_SERVER = srcs/server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(MAKE) --no-print-directory -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(MAKE) --no-print-directory -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) $(PRINTF) -o $(NAME_SERVER)

clean:
	$(MAKE) clean -C ./ft_printf
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)
re: fclean all