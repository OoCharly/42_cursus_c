# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/30 15:58:52 by cdesvern          #+#    #+#              #
#    Updated: 2016/06/06 10:58:21 by cdesvern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS =
D_INCLUDES = ./libft/includes
D_LIBFT = ../libft/
LIBFT = libft.a
SRCS = ft_printf_chainer.c ft_printf_parser.c ft_printf_renderers.c\
	   ft_printf_precision.c ft_printf_fw_parser.c ft_printf.c\

OBJS = $(subst .c,.o,$(SRCS))

all: $(NAME)

$(NAME):
	@make -C $(D_LIBFT)
	@clang -I $(D_INCLUDES) $(FLAGS) -c $(SRCS)
	@libtool -static -o $(NAME) $(OBJS) $(D_LIBFT)$(LIBFT)
	@ranlib $(NAME)

clean:
	@make clean -C $(D_LIBFT)
	@/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C $(D_LIBFT)
	@/bin/rm -f $(NAME)

re: fclean all
