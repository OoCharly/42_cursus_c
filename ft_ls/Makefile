# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/09 15:01:55 by cdesvern          #+#    #+#              #
#    Updated: 2016/10/19 21:43:04 by cdesvern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Wextra -Werror 
D_LIB = ./lib/ft_printf/
D_INCLUDES = ./lib/includes/

SRCS = ft_ls.c ls_get_info.c ls_gets.c ls_multiarg.c ls_prelim.c ls_print.c\
	   ls_rsort.c ls_sort.c main.c ls_util.c ls_util_2.c ls_gets2.c\
	   ls_fetch_info.c ls_prints.c ls_clr_prints.c ls_errors.c

all: $(NAME)

$(NAME):
	@make -C $(D_LIB)
	@clang $(FLAGS)-I $(D_INCLUDES) -L $(D_LIB) -lftprintf -o $(NAME) $(SRCS)

clean:
	@make clean -C $(D_LIB)

fclean: clean
	@make fclean -C $(D_LIB)
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
