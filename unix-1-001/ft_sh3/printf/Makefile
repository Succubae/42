#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/11 18:31:20 by rgary             #+#    #+#              #
#    Updated: 2014/01/21 15:17:30 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = 	ft_printf.c \
		ft_find_arg_params.c \
		ft_deal_with_types_and_conversion.c \
		ft_deal_with_conversions.c\
		ft_build_options_list.c \
		ft_create_options_struct.c \
		ft_print_out.c \
		ft_call_build_arg_list.c\
		ft_build_arg_list.c \
		ft_build_padding.c \
		ft_write_padding.c \
		ft_conversion_base_x.c

OBJ = $(SRC:.c=.o)

GCC = gcc -g
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^

%.o: %.c
	$(GCC) $(FLAG) -c -o $@ $^ -I../includes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
