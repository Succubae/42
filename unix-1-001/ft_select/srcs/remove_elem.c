/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 11:51:13 by rgary             #+#    #+#             */
/*   Updated: 2014/01/09 13:04:30 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "select.h"

void		remove_any_elem(t_select **s, int j)
{
	int			i;
	t_select	*save;
	t_select	*prev;

	i = 0;
	prev = NULL;
	save = *s;
	while (i < j && *s != NULL)
	{
		if (*s != NULL)
		{
			prev = *s;
			*s = prev->next;
		}
		i++;
	}
	if (prev != NULL && (*s) != NULL)
		prev->next = (*s)->next;
	(*s)->next = NULL;
	*s = save;
}

void		remove_first_elem(t_select **s)
{
	t_select	*prev;

	prev = *s;
	*s = prev->next;
	prev->next = NULL;
	free(prev);
}

void		delete_arg(t_termdata *td, t_select **s)
{
	int		j;
	char	*move;

	move = tgetstr("cm", NULL);
	j = (td->poslin * td->wnbr) + (td->poscol / (td->padlength + 1));
	if (j == 0)
		remove_first_elem(s);
	else
		remove_any_elem(s, j);
	rebuild_arg_list(s);
	ft_print_arg(td, (*s));
	move_cursor(0, 0, td, *s);
}
