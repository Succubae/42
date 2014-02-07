#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/26 11:21:45 by rgary             #+#    #+#              #
#    Updated: 2013/12/27 12:29:58 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = push_swap

LIBNAME = libps.a

INCLUDE = ./includes/

INCLUDELIBFT = ./srcs/libft/

INCLUDEPRINTF = ./srcs/printf/includes/

SRCS = srcs/ft_build_list_a.c srcs/ft_cut_a.c srcs/ft_operate_on_a.c \
	srcs/ft_operate_on_b.c srcs/ft_operate_on_both.c srcs/ft_swap_both.c \
	srcs/ft_sort.c srcs/ft_lstmap_unmod.c srcs/ft_compare.c srcs/ft_dijkstra.c

OBJ = $(SRCS:.c=.o)

WWW = -Wall -Wextra -Werror -pedantic

all: $(NAME)

$(NAME): $(LIBNAME)
	@make -C srcs/printf/
	@make -C srcs/libft/
	@gcc $(WWW) -g -o $(NAME) main.c -L./ -lps -L./srcs/libft/ -lft \
	-L./srcs/printf/ -lftprintf \
	-I$(INCLUDE) -I$(INCLUDELIBFT) -I$(INCLUDEPRINTF)

$(LIBNAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $(LIBNAME)

%.o: %.c
	@gcc $(WWW) -c -g -o $@ $^ -I$(INCLUDE) -I$(INCLUDELIBFT) -I$(INCLUDEPRINTF)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIBNAME)
	@/bin/rm -Rf $(NAME).dSYM
	@make fclean -C srcs/printf/
	@make fclean -C srcs/libft/

re: fclean all
