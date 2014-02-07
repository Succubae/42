/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 14:31:28 by rgary             #+#    #+#             */
/*   Updated: 2014/01/11 12:20:37 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <termcap.h>
#include <curses.h>
#include <term.h>
#include "select.h"

int			find_pad(t_select *s)
{
	int			i;
	t_select	*save;

	i = 0;
	save = s;
	while (s != NULL)
	{
		if (ft_strlen(s->arg) > (unsigned int)i)
			i = ft_strlen(s->arg);
		s = s->next;
	}
	s = save;
	return (i);
}

t_termdata	*change_term_info(t_termdata *s)
{
	static int		i = 0;
	struct termios  term;

	if (i == 0)
	{
		tputs(tgetstr("ti", NULL), 1, out);
		tputs(tgetstr("vi", NULL), 1, out);
		if (tgetent(NULL, s->termtype) == ERR)
			ft_error("tgetent error");
		if (tcgetattr(0, &term) == -1)
			ft_error("change : tcgetattr error");
		term.c_lflag &= ~(ICANON);
		term.c_lflag &= ~(ECHO);
		term.c_lflag |= ISIG;
		if (tcsetattr(0, TCSADRAIN, &term) == -1)
			ft_error("tcsetattr error");
		if ((s->tty = open(ttyname(0), O_WRONLY)) == -1)
			ft_error("Unable to open a fildes");
		i++;
	}
	return (s);
}

void		change_back_term_info(void)
{
	struct termios term;

	tputs(tgetstr("cl", NULL), 1, out);
	tputs(tgetstr("ve", NULL), 1, out);
	tputs(tgetstr("te", NULL), 1, out);
	if (tcgetattr(0, &term) == -1)
		ft_error("change back : tcgetattr error");
	term.c_lflag |= (ICANON);
	term.c_lflag |= (ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		ft_error("tcsetattr error");
}

t_termdata	*get_term_data(t_termdata *td, t_select *s)
{
	t_select	*save;

	if (!(td->termtype = getenv("TERM")))
		ft_error("getenv error");
	if (tgetent(NULL, td->termtype) == ERR)
		ft_error("tgetent error");
	td->wincol = tgetnum("co");
	td->winline = tgetnum("li");
	td->lineup = tgetstr("up", NULL);
	td->clear = tgetstr("cl", NULL);
	td->padlength = find_pad(s);
	save = s;
	while (s->next != NULL)
		s = s->next;
	td->totalarg = s->argnbr;
	s = save;
	td->tty = 0;
	return (td);
}

void		ft_print_arg(t_termdata *td, t_select *s)
{
	int			j;
	int			line;

	td = malloc_struct();
	td = get_term_data(td, s);
	td = change_term_info(td);
	if (TWC < (TPL + 1) || ((TTA * (TPL + 1) + TWC) > (TWC * TWL)))
	{
		tputs(tgetstr("cl", NULL), 1, out);
		FP2("Not enougth space to display every information", td->tty);
		while ((TWC < (TPL + 1)) || ((TTA * (TPL + 1) + TWC) > (TWC * TWL)))
			td = get_term_data(td, s);
	}
	td->wnbr = (int)(td->wincol / (td->padlength + 1));
	if (td->wnbr == 0)
		td->wnbr = 1;
	line = j = 0;
	tputs(td->clear, 1, out);
	print_arg_and_count(td, s, &line, &j);
	while (line > 0)
	{
		tputs(td->lineup, 1, out);
		line--;
	}
}
