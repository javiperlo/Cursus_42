# Standard
NAME        = push_swap

# Directories
LIBFT       = ./libft/libft.a
INC         = inc/
SRC_DIR     = srcs/

# Compiler and CFlags
CC          = gcc
CFLAGS      = -Wall -Werror -Wextra -I
RM          = rm -f

# Source Files
SRCS        =   $(SRC_DIR)commands/push.c \
                $(SRC_DIR)commands/rev_rotate.c \
                $(SRC_DIR)commands/rotate.c \
                $(SRC_DIR)commands/sort_big.c \
                $(SRC_DIR)commands/sort_three.c \
                $(SRC_DIR)commands/swap.c\
                $(SRC_DIR)push_swap/handle_errors.c \
                $(SRC_DIR)push_swap/init_a_to_b.c \
                $(SRC_DIR)push_swap/init_b_to_a.c \
                $(SRC_DIR)push_swap/push_swap.c \
                $(SRC_DIR)push_swap/split.c \
                $(SRC_DIR)push_swap/stack_init.c \
                $(SRC_DIR)push_swap/stack_utils.c

# Object Files
OBJ         = $(SRCS:.c=.o)

# Build rules
all: $(NAME)

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compile source files to object files
%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: fclean all

# Phony targets represent actions not files
.PHONY: all clean fclean re
