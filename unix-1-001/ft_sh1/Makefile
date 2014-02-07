#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/20 11:24:36 by rgary             #+#    #+#              #
#    Updated: 2013/12/26 10:57:19 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = ft_minishell1

LIBNAME = libms1.a

INCLUDE = ./includes/

INCLUDEGNL = ./srcs/gnl/

INCLUDEPRINTF = ./srcs/printf/includes/

INCLUDELIBFT = ./srcs/libft/

SRCS = srcs/ft_putqstr.c srcs/ft_strtoupper.c srcs/ft_for_builtins.c \
	srcs/ft_builtins.c srcs/ft_execute.c srcs/ft_for_builtins_2.c \
	srcs/ft_check_cd.c srcs/ft_for_cd.c srcs/ft_error.c srcs/ft_signal.c \
	srcs/ft_print_signal.c srcs/ft_for_env.c

OBJ = $(SRCS:.c=.o)

WWW = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBNAME)
	@make -C srcs/printf/
	@make -C srcs/libft/
	@gcc $(WWW) -g -o $(NAME) main.c -L./ -lms1 -L./srcs/ -lgnl \
	-L./srcs/libft/ -lft -L./srcs/printf/ -lftprintf \
	-I$(INCLUDE) -I$(INCLUDEGNL) -I$(INCLUDEPRINTF) -I$(INCLUDELIBFT)

$(LIBNAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $(LIBNAME)

%.o: %.c
	@gcc $(WWW) -c -g -o $@ $^ -I$(INCLUDE) -I$(INCLUDEGNL) -I$(INCLUDEPRINTF) \
	-I$(INCLUDELIBFT)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIBNAME)
	@/bin/rm -Rf $(NAME).dSYM
	@make fclean -C srcs/gnl/
	@make fclean -C srcs/printf/
	@make fclean -C srcs/libft/

re: fclean all
