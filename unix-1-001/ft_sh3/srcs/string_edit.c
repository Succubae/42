/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 15:47:09 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 13:17:33 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh3.h"

void	delete_left(t_print *print)
{
	int		i;

	remove_left_symbole();
	print->pos -= 1;
	i = print->pos;
	while (print->line[i] != '\0' && print->line[i + 1] != '\0')
	{
		print->line[i] = print->line[i + 1];
		i++;
	}
	print->line[i] = '\0';
}

void	delete_right(t_print *print)
{
	int		i;

	tputs(tgetstr("dm", NULL), 1, out);
	tputs(tgetstr("dc", NULL), 1, out);
	tputs(tgetstr("de", NULL), 1, out);
	i = print->pos;
	while (print->line[i] != '\0' && print->line[i + 1] != '\0')
	{
		print->line[i] = print->line[i + 1];
		i++;
	}
	print->line[i] = '\0';
}

void	insert_char(char *c, t_print *print)
{
	int		i;

	i = 0;
	tputs(tgetstr("im", NULL), 1, out);
	tputs(tgetstr("ic", NULL), 1, out);
	write(1, c, 1);
	if (print->pos != (i = ft_strlen(print->line)))
	{
		while (i >= print->pos)
		{
			print->line[i + 1] = print->line[i];
			i--;
		}
		print->line[print->pos] = c[0];
	}
	print->line[print->pos] = c[0];
	print->pos += 1;
	tputs(tgetstr("ip", NULL), 1, out);
	tputs(tgetstr("ei", NULL), 1, out);
}

void	remove_left_symbole(void)
{
	tputs(tgetstr("le", NULL), 1, out);
	tputs(tgetstr("dm", NULL), 1, out);
	tputs(tgetstr("dc", NULL), 1, out);
	tputs(tgetstr("de", NULL), 1, out);
}

void	re_print_line(t_print *print)
{
	int		i;
	int		j;
	char	*prompt;

	tputs(tgetstr("ei", NULL), 1, out);
	prompt = retrieve_prompt(NULL);
	j = ft_strlen(print->line) - print->pos + 1;
	while (j--, j > 0)
		tputs(tgetstr("nd", NULL), 1, out);
	i = ft_strlen(print->line) + ft_strlen(prompt) + 4;
	while (i--, i > 0)
		remove_left_symbole();
	print_prompt(prompt);
	write(1, print->line, ft_strlen(print->line));
	tputs(tgetstr("cd", NULL), 1, out);
	i = ft_strlen(print->line) + 1;
	while (i--, i != print->pos)
		tputs(tgetstr("le", NULL), 1, out);
	tputs(tgetstr("im", NULL), 1, out);
}
