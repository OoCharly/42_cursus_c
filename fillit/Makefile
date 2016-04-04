NAME = fillit

SRC = read.c verify_neighbors.c helpers.c tetros_to_left.c \
	  	solve.c main.c ft_putstr.c ft_strlen.c free_em_all.c ft_memalloc.c

OBS = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		@clang -o $(NAME) $(FLAGS) $(SRC)

clean:
		@rm -rf $(OBS)

fclean: clean
		@rm -rf $(NAME)
debug: fclean
		@clang -o $(NAME) $(SRC)
re: fclean all
