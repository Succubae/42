#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/06 17:52:57 by rgary             #+#    #+#              #
#    Updated: 2014/02/13 16:23:44 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libgnl.a

INCLUDE = ../includes/

SRCS = get_next_line.c

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

%.o: %.c
	gcc -g $(FLAG) -c -o $@ $^ -I$(INCLUDE)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
