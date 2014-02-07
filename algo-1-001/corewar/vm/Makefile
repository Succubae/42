# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 18:06:25 by mfaye             #+#    #+#              #
#    Updated: 2014/01/31 14:04:50 by rgary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

FCTDIR = func/

FCT =	add.c		\
		aff.c		\
		and.c		\
		fork.c		\
		ld.c		\
		ldi.c		\
		lfork.c		\
		live.c		\
		lld.c		\
		lldi.c		\
		or.c		\
		st.c		\
		sti.c		\
		sub.c		\
		tools.c		\
		tools_2.c	\
		xor.c		\
		zjmp.c

SRC =	cycling_machine.c	\
		display.c			\
		error_1.c			\
		error_2.c			\
		heroes_load.c		\
		heroes_tools.c		\
		ima_fruiiiiiiit.c	\
		lexer.c				\
		main.c

SRC += $(addprefix $(FCTDIR), $(FCT))

OBJ = $(SRC:.c=.o)

LIBFT = -L ../libft -lft
LIBPF = -L ../printf -lftprintf

GCC = gcc -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) -o $@ $^ $(LIBFT) $(LIBPF)

%.o: %.c
	$(GCC) -c -o $@ $^ -I../includes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
