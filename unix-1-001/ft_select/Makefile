#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/02 12:46:07 by rgary             #+#    #+#              #
#    Updated: 2014/01/09 12:11:56 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_select

LIBNAME = libselect.a

SRCS = srcs/ft_error.c srcs/ft_print_arg.c srcs/ft_select.c \
	srcs/wait_and_read.c srcs/ft_second_arg_func.c srcs/remove_elem.c

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

FLAGAP = -ansi -pedantic

INCLUDE = includes/

PRINTF = srcs/printf/

INCLUDEPRINTF = srcs/printf/includes/

LIBFT = srcs/libft/

all: $(NAME)

$(NAME): $(LIBNAME)
	make -C $(PRINTF)
	make -C $(LIBFT)
	gcc $(FLAG) $(FLAGAP) -g -I$(INCLUDE) -I$(INCLUDEPRINTF) -I$(LIBFT) \
	-L./ -lselect -L$(PRINTF) -lftprintf -L$(LIBFT) -lft -ltermcap -o \
	$(NAME) main.c

$(LIBNAME): $(OBJ)
	ar rc $@ $^
	ranlib $(LIBNAME)

%.o:%.c
	gcc $(FLAG) -g -c -o $@ $^ -I$(INCLUDE) -I$(INCLUDEPRINTF) -I$(LIBFT)

clean:
	/bin/rm -f $(LIBNAME)
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C $(PRINTF)
	make fclean -C $(LIBFT)
	/bin/rm -Rf $(NAME).dSYM
	/bin/rm -f $(NAME)

re: fclean all
