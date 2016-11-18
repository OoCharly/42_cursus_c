# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 13:55:29 by cdesvern          #+#    #+#              #
#    Updated: 2016/11/18 14:25:50 by cdesvern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Wextra -Werror
D_LIB = ./libft/
D_INCLUDES = ./libft/includes/

SRCS =  main.c msh_array_info.c	msh_array_manipulation.c msh_cd.c\
		msh_echo.c msh_entry_parser.c msh_env.c msh_error.c msh_exit.c\
		msh_export.c msh_init.c msh_launch.c msh_parse_cmd.c msh_read_cmd.c\
		msh_setenv.c msh_strspacesplit.c msh_strsplit.c msh_unsetenv.c

all: $(NAME)

$(NAME):
	@make -C $(D_LIB)
	@clang $(FLAGS) -I $(D_INCLUDES) -L $(D_LIB) -o $(NAME) $(SRCS) -lft

clean:
	@make clean -C $(D_LIB)

fclean: clean
	@make fclean -C $(D_LIB)
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
