# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 21:32:36 by cdesvern          #+#    #+#              #
#*   Updated: 2016/07/29 13:20:56 by cdesvern         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
D_INCLUDES = ../includes

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_memalloc.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_strnrchr.c\
	ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
	ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
	ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstdel.c ft_lstdelone.c\
	ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_pow.c ft_lst_at_size.c\
	ft_lstcreate.c ft_lstadd_end.c ft_lstpnew.c ft_ntoa_base.c ft_ntoa.c\
	ft_putstr_color.c ft_strndup.c get_next_line.c ft_strnchr.c ft_stroccur.c\
	ft_strnoccur.c ft_lstsumsize.c ft_nsize_base.c ft_wchar_to_string.c\
	ft_wstring_to_string.c ft_capitalize.c ft_strfjoin.c ft_del_node.c\
	ft_lstdelfst.c ft_char_to_string.c ft_wstrlen.c ft_getenv.c ft_strfcat.c\
	ft_lstsort.c ft_umax.c

OBJS = $(subst .c,.o,$(SRCS))

all: $(NAME)

$(NAME):
	@clang -I $(D_INCLUDES) $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
