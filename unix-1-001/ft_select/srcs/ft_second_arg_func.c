/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_arg_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 15:47:16 by rgary             #+#    #+#             */
/*   Updated: 2014/01/09 12:16:52 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "select.h"

t_termdata	*malloc_struct(void)
{
	static t_termdata	*td = NULL;

	if (td == NULL)
		td = (t_termdata*)malloc(sizeof(t_termdata));
	return (td);
}

int			out(int i)
{
	t_termdata	*td;

	td = malloc_struct();
	write(td->tty, &i, 1);
	return (i);
}

void		print_selected(t_termdata *td, t_select *s)
{
	int		select;

	select = (td->poslin * td->wnbr) + (td->poscol / (td->padlength + 1));
	if (s->argnbr == (select + 1))
	{
		tputs(tgetstr("us", NULL), 1, out);
		FP2(s->arg, td->tty);
		tputs(tgetstr("ue", NULL), 1, out);
	}
	else
		FP2(s->arg, td->tty);
}

void		print_with_mod(t_termdata *td, t_select *s)
{
	int		i;

	i = ft_strlen(s->arg);
	if (s->selected % 2 == 1)
	{
		tputs(tgetstr("mr", NULL), 1, out);
		print_selected(td, s);
		tputs(tgetstr("me", NULL), 1, out);
		while (i++, i <= td->padlength + 1)
			FP2(" ", td->tty);
	}
	else
	{
		print_selected(td, s);
		while (i++, i <= td->padlength + 1)
			FP2(" ", td->tty);
	}
}

void		print_arg_and_count(t_termdata *td, t_select *s, int *line, int *j)
{
	int		i;

	while (s != NULL)
	{
		i = -1;
		while (i++, i < td->wnbr && s != NULL)
		{
			print_with_mod(td, s);
			s = s->next;
			if (s != NULL)
				s->poscol = (td->padlength + 1) * i;
			*j += 1;
		}
		*line += 1;
		if (s != NULL)
			s->posline = *line;
		FP2("\n", td->tty);
	}
	td->totalline = *line;
	td->totalarg = *j;
	if ((td->lastline = td->totalarg % td->wnbr) == 0)
		td->lastline = td->wnbr;
}
