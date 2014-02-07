#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/28 12:12:20 by rgary             #+#    #+#              #
#    Updated: 2014/01/15 14:13:59 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

LIBNAME = libwolf3d.a

INCLUDE = ./includes/

INCLUDEGNL = ./srcs/gnl/

INCLUDELIBFT = ./srcs/gnl/libft/

SDL_LIB = -LSDL/SDL2/lib -lSDL2

SDL_INCLUDE = -Iincludes/SDL2

SRCS = srcs/ft_calc.c srcs/ft_draw.c srcs/ft_keyhook.c srcs/math.c \
	srcs/error.c srcs/ft_get_land_data.c srcs/ft_atoi.c \
	srcs/ft_str_nbr_split.c srcs/create_tex_coor.c

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBNAME)
	cd SDL/ ; make SDL2
	make -C srcs/gnl/
	make -C srcs/gnl/libft/
	gcc $(FLAG) -O3 -g -o $(NAME) main.c -L./ -lwolf3d $(SDL_LIB) -Lsrcs/gnl/ \
	-lgnl -Lsrcs/gnl/libft/ -lft -I$(INCLUDE) \
	-I$(INCLUDEGNL) -I$(INCLUDELIBFT) $(SDL_INCLUDE)

$(LIBNAME): $(OBJ)
	ar rc $@ $^
	ranlib $(LIBNAME)

%.o: %.c
	gcc $(FLAG) -c -g -o $@ $^ -I$(INCLUDE) -I$(INCLUDEGNL) -I$(INCLUDELIBFT) \
	$(SDL_INCLUDE)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(LIBNAME)
	/bin/rm -f $(NAME)
	/bin/rm -Rf $(NAME).dSYM
	make fclean -C srcs/gnl/
	make fclean -C srcs/gnl/libft/
	/bin/rm -Rf SDL/SDL2/junk/
	/bin/rm -Rf SDL/SDL2-2.0.1/

re: fclean all
