/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 18:19:58 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/18 16:05:33 by cwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "asm.h"

void	mai_error(void)
{
	if (errno != 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(errno);
	}
}

t_lexer	*mai_lexer_and_parser(int fd)
{
	t_lexer	*lexed;

	if ((lexed = lex_lexer(fd)) == NULL)
		exit(-1);
	close(fd);
	if (par_parser(lexed) != ASM_SUCCESS)
		exit(-2);
	par_clear_lst(&lexed);
	par_clear_empty_line(&lexed);
	return (lexed);
}

void	mai_labeler_and_encoder(t_lexer *lexed, char *av)
{
	t_start	*start;
	t_label	*label;

	start = NULL;
	label = NULL;
	if (lab_firstpass(av, lexed, &start, &label) != ASM_SUCCESS)
		exit(-3);
	ft_printf("Assembling %s:\n", av);
	write(1, "          ", 8);
	write(1, start->name + 1, (ft_strlen(start->name) - 2));
	write(1, "\n        ", 9);
	write(1, start->comment + 1, (ft_strlen(start->comment) - 2));
	write(1, "\n", 1);
	if (enc_encoding(start, label) != ASM_SUCCESS)
		exit(-4);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	t_lexer	*lexed;

	i = 1;
	if (ac < 2)
		err_usage();
	else
	{
		while (av[i] != NULL)
		{
			errno = 0;
			if ((fd = open(av[i], O_RDONLY)) != -1)
			{
				lexed = mai_lexer_and_parser(fd);
				mai_labeler_and_encoder(lexed, av[i]);
			}
			mai_error();
			i++;
		}
	}
	return (0);
}
