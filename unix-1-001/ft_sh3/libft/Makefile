#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:36:09 by rgary             #+#    #+#              #
#    Updated: 2014/01/27 18:22:39 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libft.a

EXECNAME = testlib

INCLUDE = ../includes/

SRC = ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c \
	ft_memcmp.c ft_strlen.c ft_strdup.c \
	ft_strcpy.c ft_strncpy.c ft_strcat.c \
	ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strnstr.c \
	ft_strcmp.c ft_strncmp.c ft_atoi.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_toupper.c \
	ft_tolower.c ft_memalloc.c ft_memdel.c \
	ft_putchar.c ft_putstr.c ft_strnew.c \
	ft_strdel.c ft_strclr.c ft_striter.c \
	ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c \
	ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	ft_itoa.c ft_putchar.c ft_putchar_fd.c \
	ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	ft_lstcount.c ft_word_count.c ft_build_length_tab.c \
	ft_strsplitlst.c ft_star.c ft_padding.c \
	ft_strichr.c ft_strnjoin.c ft_putnbrl.c \
	ft_strsub.c ft_strirchr.c

OBJ = $(SRC:.c=.o)

WWW = -Wall -Wextra -Werror -ansi -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

%.o: %.c
	gcc $(WWW) -g -c -o $@ $^ -I$(INCLUDE)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(EXECNAME)

re: fclean all

prog: re
	gcc $(WWW) mainlibft.c -I./ -L. -lft -o $(EXECNAME)
	./testlib
