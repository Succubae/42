# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 14:27:10 by mfaye             #+#    #+#              #
#    Updated: 2014/02/02 15:00:34 by rgary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ASM = asm/asm
COREWAR = vm/corewar
LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a
NAME = @echo "corewar"

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(COREWAR) $(ASM)
	$(NAME)

libft: $(LIBFT)

$(LIBFT):
	make -C libft/

$(PRINTF):
	make -C printf/

$(COREWAR):
	make -C vm/

$(ASM):
	make -C asm/

clean:
	make -C libft/ clean
	make -C printf/ clean
	make -C asm/ clean
	make -C vm/ clean

fclean: clean
	make -C libft/ fclean
	make -C printf/ fclean
	make -C asm/ fclean
	make -C vm/ fclean

re: fclean all

.PHONY: clean, fclean, re
