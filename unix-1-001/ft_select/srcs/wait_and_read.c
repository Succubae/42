/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_and_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 15:55:47 by rgary             #+#    #+#             */
/*   Updated: 2014/01/10 10:23:52 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "select.h"

t_select	*malloc_select(char **argv)
{
	int					i;
	static t_select		*s = NULL;

	i = 0;
	if (s == NULL && argv != NULL)
	{
		while (i++, argv[i] != NULL)
			s = build_arg_list(argv[i], s, i);
	}
	return (s);
}

void		select_arg(t_termdata *td, t_select *s)
{
	int			i;
	int			j;
	t_select	*save;

	i = 0;
	j = (td->poslin * td->wnbr) + (td->poscol / (td->padlength + 1));
	save = s;
	while (i < j)
	{
		if (s != NULL)
			s = s->next;
		i++;
	}
	s->selected += 1;
	s = save;
	ft_print_arg(td, s);
}

void		space_pressed(t_termdata *td, t_select *s)
{
	select_arg(td, s);
	move_cursor(1, 0, td, s);
}

void		wait_while_read(t_termdata *td, t_select *s)
{
	char	buf[50];

	while (1)
	{
		if (s == NULL)
			return ;
		ft_bzero(buf, 50);
		read(0, buf, 50);
		if (IS_ESC(buf))
			return ;
		else if (IS_LEFT(buf))
			move_cursor(-1, 0, td, s);
		else if (IS_RIGHT(buf))
			move_cursor(1, 0, td, s);
		else if (IS_UP(buf))
			move_cursor(0, 1, td, s);
		else if (IS_DOWN(buf))
			move_cursor(0, -1, td, s);
		else if (IS_SPACE(buf))
			space_pressed(td, s);
		else if (IS_DELETE(buf) || IS_DEL(buf))
			delete_arg(td, &s);
		else if (IS_ENTER(buf))
			return_selection(td, s);
	}
}

void		return_selection(t_termdata *td, t_select *s)
{
	change_back_term_info();
	close(td->tty);
	while (s != NULL)
	{
		if (s->selected % 2 == 1)
		{
			write(1, s->arg, ft_strlen(s->arg));
			write(1, " ", 1);
		}
		s = s->next;
	}
	exit(0);
}
