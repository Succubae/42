#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/02 14:19:32 by rgary             #+#    #+#              #
#    Updated: 2013/12/13 20:38:33 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libgnl.a

EXECNAME = test

INCLUDE = ./

INCLUDELIBFT = ./libft/

SRC = 	get_next_line.c \
		main.c

OBJ = $(SRC:.c=.o)

WWW = -Wall -Wextra -Werror -ansi -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	cd libft; make
	ar rc $@ $^
	ranlib $(NAME)

%.o: %.c
	cc $(WWW) -c -g -o $@ $^ -I$(INLCUDE) -I$(INCLUDELIBFT)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(EXECNAME)
	cd libft; make fclean

re: fclean all

prog: $(NAME)
	gcc $(WWW) -g -o $(EXECNAME) $^ main.c -I$(INCLUDE) -I$(INCLUDELIBFT) -L. \
-lgnl -L./libft/ -lft
	./$(EXECNAME)
