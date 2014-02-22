/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_shifted_keys.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 11:43:54 by rgary             #+#    #+#             */
/*   Updated: 2014/02/22 14:51:19 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "string_edit.h"

int		pressed_shift_left(char *c, t_print *print)
{
	int		i;
	int		j;

	if (!IS_S_LEFT(c))
		return (0);
	i = 1;
	j = print->pos;
	if (LINE[j - i] == ' ')
		i++;
	while ((j - i) > 0 && LINE[j - i] != ' ')
		i++;
	j = i;
	while (j > 0)
	{
		tputs(tgetstr("le", NULL), 1, out);
		j--;
	}
	print->pos -= i - 1;
	return (1);
}

int		pressed_shift_right(char *c, t_print *print)
{
	int		i;
	int		j;

	if (!IS_S_RIGHT(c))
		return (0);
	i = print->pos;
	j = 0;
	while (LINE[i + j] == ' ' && LINE[i + j] != '\0')
	{
		tputs(tgetstr("nd", NULL), 1, out);
		j++;
	}
	while (LINE[i + j] != ' ' && LINE[i + j] != '\0')
	{
		tputs(tgetstr("nd", NULL), 1, out);
		j++;
	}
	print->pos += j;
	return (1);
}

int		pressed_shift_up(char *c, t_print *print)
{
	int		i;
	int		j;
	int		col;
	char	*prompt;

	if (!IS_S_UP(c))
		return (0);
	prompt = retrieve_prompt(NULL);
	i = ft_strlen(prompt);
	j = ft_strlen(print->line);
	col = tgetnum("co");
	if ((i + j) < col)
		ft_to_get_under_25_lines_1(print);
	else
	{
		while (print->pos > 0 && col > 0)
		{
			tputs(tgetstr("le", NULL), 1, out);
			col -= 1;
			print->pos -= 1;
		}
	}
	return (1);
}

int		pressed_shift_down(char *c, t_print *print)
{
	int		i;
	int		j;
	int		col;
	char	*prompt;

	if (!IS_S_DOWN(c))
		return (0);
	prompt = retrieve_prompt(NULL);
	i = ft_strlen(prompt);
	j = ft_strlen(print->line);
	col = tgetnum("co");
	if ((i + j) < col)
		ft_to_get_under_25_lines_2(print, i, j);
	else
	{
		while (print->pos < j && col > 0)
		{
			tputs(tgetstr("nd", NULL), 1, out);
			col -= 1;
			print->pos += 1;
		}
	}
	return (1);
}
