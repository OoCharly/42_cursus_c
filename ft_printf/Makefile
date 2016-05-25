# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/25 14:05:22 by cdesvern          #+#    #+#              #
#    Updated: 2016/05/25 14:08:36 by cdesvern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
D_INCLUDES = ./

SRCS = ft_printf.c chainer.c renderers.c flags.c parser.c

OBJS = $(subst .c,.o,$(SRCS))

all: $(NAME)

$(NAME):
	@clang -c $(SRCS) -L ../libft -lft
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
