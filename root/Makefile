##
## Makefile for make in /home/ceccat_j/c/
## 
## Made by jerome ceccato
## Login   <ceccat_j@epitech.net>
## 
## Started on  Mon Oct 19 12:54:08 2009 jerome ceccato
## Last update Wed Apr 21 12:02:20 2010 jerome ceccato
##

NAME	= lem-in

SRCS	= main.c	\
	gr_error.c	\
	gr_free.c	\
	gr_new.c	\
	gr_utils.c	\
	gr_search.c	\
	graph.c		\
	getnbr.c	\
	get_next_line.c	\
	my_cmp.c	\
	my_isspace.c	\
	my_str.c	\
	my_strdup.c	\
	my_strlen.c	\
	read_infos.c	\
	list.c		\
	setflag.c	\
	move.c		\
	free.c

OBJS	= $(SRCS:.c=.o)
CC	= cc
RM	= rm -f
OFLAGS	= -O2
CFLAGS	= -W -Wall -pedantic $(OFLAGS)

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(OFLAGS)

clean	:
	$(RM) $(OBJS)
	$(RM) *~

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
