/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_edit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 14:18:35 by rgary             #+#    #+#             */
/*   Updated: 2014/02/22 14:49:12 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_edit.h"

void	insert_string(char *c, t_print *print)
{
	int		i;

	i = 0;
	while (c[i] != '\0')
	{
		insert_char(c[i], print);
		i++;
	}
}

void	move_cursor_to_end_of_line(t_print *print)
{
	int     i;
	int     j;
	char    *prompt;

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
}


void	check_length_and_realloc(t_print *print)
{
	int		i;
	int		l;
	int		m;
	char	*tmp;

	i = 0;
	l = print->length % 255;
	m = print->length;
	if (l > 253)
	{
		while (m % 255 != 0)
			m++;
		tmp = ft_strdup(print->line);
		free(print->line);
		print->line = ft_strnew(m + 256);
		while (tmp[i] != '\0')
		{
			print->line[i] = tmp[i];
			i++;
		}
	}
	print->length += 1;
}

char	*cpy_history(char *histo)
{
	int		i;
	int		l;
	char	*line;

	i = 0;
	line = NULL;
	l = ft_strlen(histo);
	while (l % 255 != 0)
		l++;
	line = ft_strnew(l + 1);
	while (histo[i] != '\0')
	{
		line[i] = histo[i];
		i++;
	}
	return (line);
}
