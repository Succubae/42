#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/06 17:52:57 by rgary             #+#    #+#              #
#    Updated: 2014/01/06 17:52:58 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIBNAME = libgnl.a

INCLUDE = ./

INCLUDELIBFT = ./libft/

SRCS = get_next_line.c

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(LIBNAME)

$(LIBNAME): $(OBJ)
	ar rc $@ $^
	ranlib $(LIBNAME)

%.o: %.c
	gcc $(FLAG) -c -o $@ $^ -I$(INCLUDE) -I$(INCLUDELIBFT)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(LIBNAME)

re: fclean all
