/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_more_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 12:09:45 by rgary             #+#    #+#             */
/*   Updated: 2014/02/22 14:48:03 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "string_edit.h"

int		pressed_key_home(char *c, t_print *print)
{
	int		i;
	int		j;

	if (!IS_HOME(c))
		return (0);
	i = ft_strlen(print->line);
	j = i - print->pos;
	i -= j;
	while (i > 0)
	{
		tputs(tgetstr("le", NULL), 1, out);
		i--;
	}
	print->pos = 0;
	return (1);
}

int		pressed_key_end(char *c, t_print *print)
{
	int		i;

	if (!IS_END(c))
		return (0);
	i = ft_strlen(print->line);
	i -= print->pos;
	while (i > 0)
	{
		tputs(tgetstr("nd", NULL), 1, out);
		i--;
	}
	print->pos = ft_strlen(print->line);
	return (1);
}

int		pressed_key_tab(char *c, t_print *print)
{
	if (!IS_TAB(c))
		return (0);
	(void)print;
	return (1);
}

int		pressed_key_del(char *c, t_print *print)
{
	if (!IS_DEL(c))
		return (0);
	if (print->pos < (int)ft_strlen(print->line))
		delete_right(print);
	return (1);
}
