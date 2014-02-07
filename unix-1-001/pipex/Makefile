#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 11:26:07 by rgary             #+#    #+#              #
#    Updated: 2013/12/31 11:36:44 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = pipex

LIBNAME = libpipex.a

SRCS = srcs/ft_check_things.c srcs/ft_environ.c srcs/ft_error.c srcs/ft_pipe.c \
	srcs/ft_error_2.c

OBJ = $(SRCS:.c=.o)

INCLUDE = includes/

INCLUDEPRINTF = srcs/printf/includes

INCLUDELIBFT = srcs/libft/

FLAG = -Wall -Wextra -Werror -ansi -pedantic

all: $(NAME)

$(NAME): $(LIBNAME)
	make -C srcs/printf/
	make -C srcs/libft/
	gcc $(FLAG) -o $(NAME) main.c -g -L./ -lpipex \
	-L./srcs/printf/ -lftprintf -L./srcs/libft/ -lft -I$(INCLUDE) \
	-I$(INCLUDEPRINTF) -I$(INCLUDELIBFT)

$(LIBNAME): $(OBJ)
	ar rc $@ $^
	ranlib $(LIBNAME)

%.o: %.c
	gcc $(FLAG) -c -g -o $@ $^ -I$(INCLUDE) -I$(INCLUDEPRINTF) \
	-I$(INCLUDELIBFT)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(LIBNAME)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C srcs/printf/
	make fclean -C srcs/libft/

re: fclean all
