#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/11 18:31:20 by rgary             #+#    #+#              #
#    Updated: 2013/12/20 18:57:26 by rgary            ###   ########.fr        #
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
		ft_conversion_base_x.c \
		srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_putnbr.c \
		srcs/ft_putnbrl.c \
		srcs/ft_atoi.c \
		srcs/ft_strlen.c \
		srcs/ft_strsub.c \
		srcs/ft_strdup.c \
		srcs/ft_bzero.c \
		srcs/ft_memset.c \
		srcs/ft_putendl.c \
		srcs/ft_strncmp.c \
		srcs/ft_itoa.c \
		srcs/ft_strichr.c

OBJ = $(SRC:.c=.o)

GCC = gcc -g
FLAG = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^

%.o: %.c
	@$(GCC) $(FLAG) -c -o $@ $^ -Iincludes

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f test.out

re: fclean all

prog:
	@$(GCC) -L. -lftprintf -o test.out main.c
