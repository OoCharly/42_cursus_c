NAME = fillit

SRC = read.c verify_neighbors.c helpers.c tetros_to_left.c \
	solve.c main.c

OBS = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIB_DIR = ./libft
LIB = lft

all: $(NAME)

$(NAME):
	@clang -o $(NAME) $(FLAGS) $(SRC) -L $(LIB_DIR) -$(LIB)

clean:
	@rm -rf $(OBS)

fclean: clean
	@rm -rf $(NAME)
debug: fclean
	@clang -o $(NAME) $(SRC) -L $(LIB_DIR) -$(LIB)
re: fclean all
