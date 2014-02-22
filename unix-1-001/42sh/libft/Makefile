# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:07:06 by mfaye             #+#    #+#              #
#    Updated: 2014/01/17 14:32:30 by cwagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_atoi.c \
		ft_bzero.c \
		ft_error.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_stoa.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strichr.c \
		ft_strjoin.c \
		ft_strjoinc.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnew.c \
		ft_strpad.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strsplitwhite.c \
		ft_strsub.c \
		ft_utoa.c \
		get_next_line.c \
		ft_putnbr_fd.c \
		ft_strtrim.c \
		ft_strrev.c \
		ft_putendl_fd.c\
		ft_strglue.c\
		ft_countsplit.c

OBJ = $(SRC:.c=.o)

GCC = gcc -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

%.o: %.c
	$(GCC) -c -o $@ $^ -I../includes


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
