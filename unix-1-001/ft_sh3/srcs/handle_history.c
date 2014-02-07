/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 17:44:58 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 13:04:18 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh3.h"

t_history	*store_history(t_history *lnk, int i)
{
	static t_history	*stk = NULL;

	(void)i;
	if (stk == NULL)
		stk = lnk;
	return (stk);
}

char		*get_line_from_history(t_history *lnk, int i)
{
	lnk = store_history(lnk, i);
	if (lnk != NULL)
	{
		write(1, lnk->line, ft_strlen(lnk->line));
		return (lnk->line);
	}
	return (NULL);
}

t_history	*create_first_lnk(char *line)
{
	t_history	*start;

	start = (t_history*)malloc(sizeof(t_history));
	start->line = ft_strdup(line);
	start->prev = NULL;
	start->next = NULL;
	return (start);
}

void		build_history_list(t_print *print)
{
	t_history	*new;

	while (print->histo && print->histo->prev)
		print->histo = print->histo->prev;
	if (print->line[0] < 32 || print->line[0] > 126)
		return ;
	new = (t_history*)malloc(sizeof(t_history));
	new->line = ft_strdup(print->line);
	new->prev = NULL;
	if (print->histo != NULL)
	{
		new->next = print->histo;
		print->histo->prev = new;
	}
	else
		new->next = NULL;
	print->histo = new;
	print->histo->prev = NULL;
}
