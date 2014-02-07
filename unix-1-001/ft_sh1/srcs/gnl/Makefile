#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/02 14:19:32 by rgary             #+#    #+#              #
#    Updated: 2013/12/20 18:57:50 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libgnl.a

INCLUDE = ./

SRC = 	get_next_line.c\
		ft_strnbchr.c\
		ft_strnjoin.c\
		ft_strnew.c\
		ft_strsub.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strlen.c\
		ft_bzero.c

OBJ = $(SRC:.c=.o)

WWW = -Wall -Wextra -Werror -ansi -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $(NAME)

%.o: %.c
	@gcc $(WWW) -c -g -o $@ $^ -I$(INCLUDE)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(EXECNAME)

re: fclean all
