#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/21 11:35:04 by rgary             #+#    #+#              #
#    Updated: 2014/02/22 10:53:01 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 42sh

PRINTF = -Lprintf/ -lftprintf
LIBFT = -Llibft/ -lft
TERM = -ltermcap

SRC =	main.c
SRCDIR = srcs/

STRING =	build_prompt.c			\
			handle_history.c		\
			handle_keys.c			\
			handle_more_keys.c		\
			handle_shifted_keys.c	\
			handle_shifted_keys2.c	\
			initiate_term.c			\
			listen.c				\
			string_edit.c			\
			string_edit2.c
STRINGDIR = srcs/string_edit/

SRCS = $(addprefix $(SRCDIR), $(SRC))
SRCS += $(addprefix $(STRINGDIR), $(STRING))

OBJ = $(SRCS:.c=.o)

FLAG = -g -Wall -Wextra -Werror

INCLUDE = -Iincludes/

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C printf/
	gcc $(FLAG) $(OBJ) -o $(NAME) $(LIBFT) $(PRINTF) $(TERM) $(INCLUDE)

%.o: %.c
	gcc $(FLAG) -c -o $@ $^ $(INCLUDE)

clean:
	rm -f $(NAME)
	make -C libft/ clean
	make -C printf/ clean

fclean: clean
	rm -f $(OBJ)
	make -C libft/ fclean
	make -C printf/ fclean

re: fclean all
