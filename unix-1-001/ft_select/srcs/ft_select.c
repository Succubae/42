/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 14:33:36 by rgary             #+#    #+#             */
/*   Updated: 2014/01/10 10:24:30 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "select.h"

void		rebuild_arg_list(t_select **s)
{
	int			i;
	t_select	*save;

	i = 1;
	save = *s;
	while (*s != NULL)
	{
		(*s)->argnbr = i;
		*s = (*s)->next;
		i++;
	}
	*s = save;
}

t_select	*build_arg_list(char *arg, t_select *s, int i)
{
	t_select	*new;
	t_select	*save;

	save = s;
	if (!(new = (t_select*)malloc(sizeof(t_select))))
		ft_error("Malloc Error while building argument list. Exit.\n");
	new->arg = ft_strdup(arg);
	new->argnbr = i;
	new->poscol = 0;
	new->posline = 0;
	new->next = NULL;
	if (s == NULL)
		return (new);
	while (s->next != NULL)
		s = s->next;
	s->next = new;
	return (save);
}

void		move_cursor(int x, int y, t_termdata *td, t_select *s)
{
	int		u;
	int		v;

	u = td->poscol + ((td->padlength + 1) * x);
	v = td->poslin + y;
	if (v == 0 && u < 0)
	{
		u = (td->lastline - 1) * (td->padlength + 1);
		v = td->totalline - 1;
	}
	if (u < 0)
	{
		u = (td->wnbr - 1) * (td->padlength + 1);
		v -= 1;
	}
	if (u > ((td->wnbr - 1) * (td->padlength + 1)))
	{
		u = 0;
		v += 1;
	}
	move_cursor_again(u, v, td, s);
}

void		move_cursor_again(int u, int v, t_termdata *td, t_select *s)
{
	char	*move;

	move = tgetstr("cm", NULL);
	if (v < 0)
		v = (td->totalline - 1);
	if (v > (td->totalline - 1))
		v = 0;
	if (v == (td->totalline - 1) && u >= td->lastline * (td->padlength + 1))
	{
		u = 0;
		v = 0;
	}
	td->poscol = u;
	td->poslin = v;
	ft_print_arg(td, s);
	tputs(tgoto(move, u, v), 1, out);
}

void		ft_select(char **argv)
{
	t_termdata	*td;
	t_select	*s;

	s = malloc_select(argv);
	td = malloc_struct();
	move_cursor(0, 0, td, s);
	ft_print_arg(td, s);
	wait_while_read(td, s);
}
