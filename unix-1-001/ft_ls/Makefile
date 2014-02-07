#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:36:09 by rgary             #+#    #+#              #
#    Updated: 2013/12/14 18:57:56 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libls.a

EXECNAME = ft_ls

INCLUDE = ./

INCLUDELIBFT = ./libft/

SRC =	ft_create_dir_content_list.c \
		ft_create_file_content_list.c \
		ft_create_dirlist_content_list.c \
		ft_fill_stats.c \
		ft_find_info_stats.c \
		ft_pad_stats.c \
		ft_sort_list.c \
		ft_sort_list_time.c \
		ft_do_by_params.c \
		ft_sort_params.c \
		ft_print_by_params.c \
		ft_print_info.c \
		ft_recursivity.c

OBJ = $(SRC:.c=.o)

WWW = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft; make
	@ar rc $@ $^
	@ranlib $(NAME)

%.o: %.c
	@gcc -g $(WWW) -c -o $@ $^ -I$(INCLUDE) -I$(INCLUDELIBFT)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(EXECNAME)
	@cd libft; make fclean

re: fclean all

prog: $(NAME)
	@gcc $(WWW) -g -O3 -o $(EXECNAME) $^ main.c -I$(INCLUDE) \
	-I$(INCLUDELIBFT) -L. -lls -Llibft/ -lft
