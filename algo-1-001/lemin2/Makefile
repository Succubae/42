#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/11 09:47:07 by rgary             #+#    #+#              #
#    Updated: 2014/02/17 13:02:21 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

INCLUDE = -Iincludes/

LIBFT = -Llibft/ -lft

GNL = -Lgnl/ -lgnl

SRCS =	build_room.c	\
		error.c			\
		ft_free.c		\
		get_info.c		\
		lexer.c			\
		main.c

SRCDIR = srcs/

SRC = $(addprefix $(SRCDIR), $(SRCS))

OBJ = $(SRC:.c=.o)

FLAG = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C gnl/
	gcc $(FLAG) -o $(NAME) $(OBJ) $(LIBFT) $(GNL) $(INCLUDE)

%.o: %.c
	gcc $(FLAG) -c -o $@ $^ $(INCLUDE)

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	make -C gnl/ fclean

re: fclean all
