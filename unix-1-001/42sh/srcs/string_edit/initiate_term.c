/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_term.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 11:26:46 by rgary             #+#    #+#             */
/*   Updated: 2014/02/22 14:48:33 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "string_edit.h"

void	ft_error(char*);

int			out(int i)
{
	t_termdata	*td;

	td = malloc_struct();
	write(td->tty, &i, 1);
	return (i);
}

t_termdata	*change_term_info(t_termdata *s)
{
	struct termios	term;

	if (tgetent(NULL, s->termtype) == ERR)
		ft_error("tgetent error");
	if (tcgetattr(0, &term) == -1)
		ft_error("change : tcgetattr error");
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		ft_error("tcsetattr error");
	if ((s->tty = open(ttyname(0), O_WRONLY)) == -1)
		ft_error("Unable to open a fildes");
	return (s);
}

void		revers_insert_mode(t_print *print)
{
	if (print->ins)
	{
		tputs(tgetstr("ei", NULL), 1, out);
		print->ins = 0;
	}
}

void		change_back_term_info(char **path)
{
	int		i;
	struct	termios term;

	i = 0;
	tputs(tgetstr("ei", NULL), 1, out);
	if (tcgetattr(0, &term) == -1)
		ft_error("change back : tcgetattr error");
	term.c_lflag = (ISIG|ICANON|ECHO|IEXTEN|ECHOE|ECHOKE|ECHOCTL);
	if (tcsetattr(0, 0, &term) == -1)
		ft_error("tcsetattr error");
	(void)path;
}

t_termdata	*malloc_struct(void)
{
	static t_termdata	*td = NULL;

	if (td == NULL)
		td = (t_termdata*)malloc(sizeof(t_termdata));
	return (td);
}
