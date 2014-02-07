#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/13 20:40:19 by rgary             #+#    #+#              #
#    Updated: 2013/12/15 12:39:37 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = hotrace

INCLUDE = ./

SRC = hotrace.c gnl/get_next_line.c\
	gnl/ft_bzero.c gnl/ft_strcpy.c gnl/ft_strdup.c gnl/ft_strlen.c\
	gnl/ft_strnbchr.c gnl/ft_strnew.c gnl/ft_strnjoin.c gnl/ft_strsub.c\
	ft_putstr.c ft_putstrendl.c make_node.c return_char_1.c return_char_2.c\
	return_char_3.c return_char_4.c return_char_5.c return_char_6.c\
	return_char_7.c return_char_8.c return_char_9.c return_char_10.c\
	return_char_11.c return_char_12.c return_char_13.c return_char_14.c\
	return_char_15.c return_char_16.c return_char_17.c return_char_18.c\
	return_char_19.c

OBJ = $(SRC:.c=.o)

WWW = -Wall -Wextra -Werror -O3

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(WWW) -o $@ $^

%.o: %.c
	gcc $(WWW) -c -g -o $@ $^ -I$(INCLUDE)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
