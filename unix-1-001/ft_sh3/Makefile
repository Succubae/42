#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgary <rgary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 10:11:25 by rgary             #+#    #+#              #
#    Updated: 2014/02/07 15:35:04 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_minishell3

LIBNAME = libsh3.a

SH1DIR = 	srcs/sh1/

SH2DIR = 	srcs/sh2/

SH3DIR =	srcs/

SH1 = 	ft_builtins.c			\
		ft_check_cd.c			\
		ft_error.c				\
		ft_execute.c			\
		ft_free.c				\
		ft_for_builtins.c		\
		ft_for_builtins_2.c		\
		ft_for_cd.c				\
		ft_for_env.c			\
		ft_print_signal.c		\
		ft_putqstr.c			\
		ft_signal.c				\
		ft_strtoupper.c			\
		ex_main.c

SH2 =	build_prompt.c			\
		build_prompt2.c			\
		build_tree.c			\
		check_commands_1.c		\
		check_commands_2.c		\
		exec_commands.c			\
		exec_commands2.c		\
		execute_tree.c			\
		lexer.c					\
		lexer_2.c				\
		operation_on_command.c	\
		free.c					\
		parser.c

SH3 =	listen.c				\
		initiate_term.c			\
		handle_history.c		\
		handle_keys.c			\
		handle_more_keys.c		\
		handle_shifted_keys.c	\
		handle_shifted_keys2.c	\
		string_edit.c

SRCS = $(addprefix $(SH1DIR), $(SH1))
SRCS += $(addprefix $(SH2DIR), $(SH2))
SRCS += $(addprefix $(SH3DIR), $(SH3))

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
	gcc -g $(MFLAG) $(INCL) -L./ -lsh3 -ltermcap $(LIBS) -o $(NAME) main.c

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
