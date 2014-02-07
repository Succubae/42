# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 18:06:25 by mfaye             #+#    #+#              #
#    Updated: 2014/02/02 13:28:44 by cwagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

PARDIR = parser/
ENCDIR = encoding/
LABDIR = label/
SRCDIR = srcs/
LEXDIR = lexing/

PARFILES = 	parser.c \
			tables.c \
			prt_err.c

LABFILES = 	label.c \
			command_1.c \
			command_2.c \
			command_3.c \
			command_4.c \
			command_5.c \
			start.c \
			label_existence.c

ENCFILES = 	encoding.c \
			write_shits.c \
		   	swap_big_endian.c \
			print_params.c

SRCFILES = 	main.c \
			error.c

LEXFILES = lex_list.c\
		   lexer.c \
		   lex_error.c\
		   lex_funcs1.c\
		   lex_funcs2.c\
		   lex_redir.c

SRC = $(addprefix $(SRCDIR), $(SRCFILES))
SRC += $(addprefix $(ENCDIR), $(ENCFILES))
SRC += $(addprefix $(LABDIR), $(LABFILES))
SRC += $(addprefix $(PARDIR), $(PARFILES))
SRC += $(addprefix $(LEXDIR), $(LEXFILES))

OBJ = $(SRC:.c=.o)

LIB = -L ../libft -lft
LIBPF = -L ../printf -lftprintf
INCLUDE = -I ../includes
GCC = gcc -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) -o $(NAME) $(OBJ) $(LIB) $(LIBPF)

%.o: %.c
	$(GCC) -c -o $@ $^ $(INCLUDE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
