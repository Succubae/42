/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 17:43:31 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 11:47:05 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh3.h"

int		pressed_key_up(char *c, t_print *print)
{
	if (!IS_UP(c))
		return (0);
	print->startsel = print->endsel = 0;
	if (print->histo != NULL)
	{
		remove_line(print);
		free(print->line);
		print->line = ft_strdup(print->histo->line);
		if (print->histo->next)
			print->histo = print->histo->next;
		print->pos = ft_strlen(print->line);
		write(1, print->line, ft_strlen(print->line));
	}
	return (1);
}

int		pressed_key_down(char *c, t_print *print)
{
	if (!IS_DOWN(c))
		return (0);
	print->startsel = print->endsel = 0;
	if (print->histo != NULL)
	{
		remove_line(print);
		if (print->histo->prev != NULL)
		{
			free(print->line);
			print->histo = print->histo->prev;
			print->line = ft_strdup(print->histo->line);
			print->pos = ft_strlen(print->line);
			write(1, print->line, ft_strlen(print->line));
		}
		else
		{
			remove_line(print);
			print->pos = 0;
		}
	}
	return (1);
}

int		pressed_key_delete(char *c, t_print *print)
{
	if (!IS_DELETE(c))
		return (0);
	print->startsel = print->endsel = 0;
	if (print->pos > 0)
		delete_left(print);
	return (1);
}

int		pressed_key_left(char *c, t_print *print)
{
	if (!IS_LEFT(c))
		return (0);
	print->startsel = print->endsel = 0;
	if (print->pos > 0)
	{
		print->ins = 1;
		tputs(tgetstr("le", NULL), 1, out);
		print->pos -= 1;
	}
	return (1);
}

int		pressed_key_right(char *c, t_print *print)
{
	if (!IS_RIGHT(c))
		return (0);
	print->startsel = print->endsel = 0;
	if (print->pos >= 0 && print->pos < (int)ft_strlen(print->line))
	{
		print->ins = 1;
		tputs(tgetstr("nd", NULL), 1, out);
		print->pos += 1;
	}
	return (1);
}
