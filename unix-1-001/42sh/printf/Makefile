# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/10 09:54:20 by mfaye             #+#    #+#              #
#    Updated: 2013/12/10 09:54:23 by mfaye            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRULE = libft/libft.a
NAME = libftprintf.a
SRC = arg.c \
	  conv.c \
	  conv_c.c \
	  conv_d.c \
	  conv_o.c \
	  conv_s.c \
	  conv_u.c \
	  conv_x.c \
 	  error.c \
 	  flags.c \
 	  flags_d.c \
 	  format_1.c \
 	  format_2.c \
 	  ft_printf.c \
 	  list.c

OBJ = $(SRC:.c=.o)

GCC = gcc -g -Wall -Wextra -Werror

all: $(LIBRULE) $(NAME)

$(LIBRULE):
	make -C ../libft/

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

%.o: %.c
	$(GCC) -c -o $@ $^ -I../includes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

42:
	@echo "THE CAKE IS NOT REAL\nTHE CAKE IS NOT REAL\nTHE CAKE IS NOT REAL\n"