#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 10:48:35 by rgary             #+#    #+#              #
#    Updated: 2013/12/18 11:21:57 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fdf

GNL = ./srcs/gnl/

INCLUDE = ./

SRCS = main.c ft_get_land_data.c ft_math.c ft_draw.c key_hook.c\
	ft_str_nbr_split.c\
	srcs/ft_bzero.c\
	srcs/ft_strjoin.c\
	srcs/ft_putendl.c\
	srcs/ft_atoi.c\
	srcs/ft_memset.c\
	srcs/ft_strlen.c\
	srcs/ft_putchar.c\
	srcs/ft_putstr.c\
	srcs/ft_strcpy.c\
	srcs/ft_strdup.c\
	srcs/ft_strichr.c\
	srcs/ft_strnew.c\
	srcs/ft_strnjoin.c\
	srcs/ft_strsub.c\
	srcs/ft_putnbrl.c\
	srcs/ft_putnbr.c

MLX = -lmlx -lXext -lX11

FLG = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(FLG) -g -o $(NAME) $(SRCS) -L/usr/X11/lib $(MLX) -I$(INCLUDE) -Lsrcs -lgnl

clean:
	/bin/rm -f $(NAME)

fclean: clean

re: fclean all

prog:
