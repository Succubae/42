/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:02:09 by rgary             #+#    #+#             */
/*   Updated: 2014/01/11 16:25:04 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <termcap.h>
#include <curses.h>
#include <term.h>
#include <signal.h>
#include <sys/ioctl.h>
#include "select.h"

void	ft_signal(int i)
{
	t_select	*s;
	t_termdata	*td;

	(void)i;
	s = malloc_select(NULL);
	td = malloc_struct();
	ft_print_arg(td, s);
}

void	ft_stop(int i)
{
	char	cp[2];
	struct termios	term;

	(void)i;
	tputs(tgetstr("ve", NULL), 1, out);
	tputs(tgetstr("te", NULL), 1, out);
	tcgetattr(0, &term);
	cp[0] = term.c_cc[VSUSP];
	cp[1] = '\0';
	term.c_lflag |= (ICANON);
	term.c_lflag |= (ECHO);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGCONT, ft_continue);
	ioctl(0, TIOCSTI, cp);
}

void	ft_continue(int i)
{
	struct termios	term;

	(void)i;
	tputs(tgetstr("ti", NULL), 1, out);
	tputs(tgetstr("vi", NULL), 1, out);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_lflag |= ISIG;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		ft_error("tcsetattr error");
	signal(SIGTSTP, ft_stop);
	signal(SIGCONT, SIG_DFL);
}

int		main(int argc, char** argv)
{
	signal(SIGWINCH, ft_signal);
	signal(SIGTSTP, ft_stop);
	signal(SIGCONT, ft_continue);
	if (argc < 2)
		ft_error("Wrong usage.\n Usage = ft_select [arg] [...].\n");
	ft_select(argv);
	change_back_term_info();
	return (0);
}
