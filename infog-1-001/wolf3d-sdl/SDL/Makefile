#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviala <aviala@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/27 18:12:48 by aviala            #+#    #+#              #
#    Updated: 2014/01/10 15:07:35 by rgary            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = SDL_Test

SRCDIR = .
OBJDIR = .
INCDIR = -I.

CFLAGS = -Wall -Wextra -Werror -ansi -pedantic -pedantic-errors
LDFLAGS = `SDL2/bin/sdl2-config --libs`
CFLAGS += `SDL2/bin/sdl2-config --cflags`

ifeq ($(DEBUG),yes)
	CC = clang
	CFLAGS += -ggdb3 -fstack-protector-all -Wshadow -Wunreachable-code \
		-Wstack-protector -pedantic-errors -O0 -W -Wundef -fno-common \
		-Wfatal-errors -Wstrict-prototypes -Wmissing-prototypes -pedantic \
		-Wwrite-strings -Wunknown-pragmas -Wdeclaration-after-statement \
		-Wold-style-definition -Wmissing-field-initializers -Wfloat-equal \
		-Wpointer-arith -Wnested-externs -Wstrict-overflow=5 -fno-common \
		-Wno-missing-field-initializers -Wswitch-default -Wswitch-enum \
		-Wbad-function-cast -Wredundant-decls -fno-omit-frame-pointer
else
	CC = gcc
	CFLAGS += -O3
endif

LD = $(CC)
SRC = main.c
OBJS = $(SRC:.c=.o)
OBJS_PREF = $(addprefix $(OBJDIR)/, $(OBJS))

all: $(SDL2) $(OBJDIR)

$(NAME): $(OBJS_PREF)
	@echo "Linking $@"
	@$(LD) -o $@ $^ $(LDFLAGS) $(INCDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "Compiling $< into $@..."
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	@echo "Removing $(OBJS_PREF)."
	@rm -f $(OBJS_PREF)

fclean: clean
	@echo "Removing $(NAME)."
	@rm -f $(NAME)

re: fclean all

# Do all the SDL2 building junk.
# Get this rule for you makefile ;)

SDL2:
	mkdir -p SDL2/junk
	wget http://www.libsdl.org/release/SDL2-2.0.1.tar.gz
	tar xf SDL2-2.0.1.tar.gz
	( cd SDL2-2.0.1 \
		&& ./configure --prefix=$(shell pwd)/SDL2/ \
		&& $(MAKE) && $(MAKE) install )
	mv SDL2-2.0.1.tar.gz SDL2-2.0.1 SDL2/junk

.PHONY: clean fclean re all SDL2
