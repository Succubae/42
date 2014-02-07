#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 10:11:25 by rgary             #+#    #+#              #
#    Updated: 2014/01/23 17:06:31 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_minishell2

LIBNAME = libsh2.a

SH1DIR = srcs/sh1/

SH2DIR = 	srcs/

SH1 = 	ft_builtins.c		\
		ft_check_cd.c		\
		ft_error.c			\
		ft_execute.c		\
		ft_for_builtins.c	\
		ft_for_builtins_2.c	\
		ft_for_cd.c			\
		ft_for_env.c		\
		ft_print_signal.c	\
		ft_putqstr.c		\
		ft_signal.c			\
		ft_strtoupper.c		\
		ex_main.c

SH2 =	build_prompt.c			\
		build_tree.c			\
		check_commands_1.c		\
		check_commands_2.c		\
		exec_commands.c			\
		exec_commands2.c		\
		execute_tree.c			\
		lexer.c					\
		lexer_2.c				\
		operation_on_command.c	\
		parser.c

SRCS = $(addprefix $(SH1DIR), $(SH1))
SRCS += $(addprefix $(SH2DIR), $(SH2))

OBJS = $(SRCS:.c=.o)

FLAG = -Wall -Werror -Wextra

MFLAG = $(FLAG) -ansi -pedantic

LLIBFT = -Llibft/ -lft

LPRINTF = -Lprintf/ -lftprintf

LGNL = -Lgnl/ -lgnl

LIBS = $(LLIBFT) $(LPRINTF) $(LGNL)

INCL = -Iincludes/

all: $(NAME)

$(NAME): $(LIBNAME)
	make -C printf/
	make -C libft/
	make -C gnl/
	gcc -g $(MFLAG) $(INCL) -L./ -lsh2 $(LIBS) -o $(NAME) main.c

$(LIBNAME): $(OBJS)
	ar rc $@ $^
	ranlib $(LIBNAME)

%.o: %.c
	gcc -c -g $(FLAG) $(INCL) -o $@ $^

clean:
	/bin/rm -f $(NAME)
	/bin/rm -Rf $(NAME).dSYM
	/bin/rm -f $(OBJS)
	/bin/rm -f $(LIBNAME)

fclean: clean
	make fclean -C gnl/
	make fclean -C printf/
	make fclean -C libft/

re: fclean all
