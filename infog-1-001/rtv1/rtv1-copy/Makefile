#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/11 13:37:36 by rgary             #+#    #+#              #
#    Updated: 2014/02/15 14:25:48 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = rtv1

SRCSDIR = srcs/

SRCS = 	build_structs.c	\
		cam_builder.c	\
		color.c			\
		fill_objlst.c	\
		look_for_obj.c	\
		main.c			\
		obj_list.c		\
		ray_tracer.c	\
		utils.c			\
		utils2.c		\
		utils3.c

SRC = $(addprefix $(SRCSDIR), $(SRCS))

FLAG = -g -Wall -Wextra -Werror -ansi -pedantic

OBJ = $(SRC:.c=.o)

LIBFT = -L libft/ -lft
GNL = -L gnl/ -lgnl
MLX = -L/usr/X11/lib -lmlx -lXext -lX11
INCLUDE = -Iincludes

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C gnl/
	gcc $(FLAG) -o $(NAME) $(OBJ) $(LIBFT) $(GNL) $(MLX) $(INCLUDE)

%.o: %.c
	gcc $(FLAG) -c -o $@ $^ $(INCLUDE)

clean:
	rm -f $(OBJ)
	rm -Rf $(NAME).dSYM

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C gnl/ fclean

re: fclean all

.PHONY: clean, fclean, re
