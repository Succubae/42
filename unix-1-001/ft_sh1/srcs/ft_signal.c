/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 11:50:36 by rgary             #+#    #+#             */
/*   Updated: 2013/12/24 12:37:24 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include "ft_sh1.h"

void	ft_signal(void)
{
	signal(SIGHUP, ft_print_kill);
	signal(SIGINT, ft_print_kill);
	signal(SIGKILL, ft_print_kill);
	signal(SIGPIPE, ft_print_kill);
	signal(SIGALRM, ft_print_kill);
	signal(SIGTERM, ft_print_kill);
	signal(SIGXCPU, ft_print_kill);
	signal(SIGXFSZ, ft_print_kill);
	signal(SIGVTALRM, ft_print_kill);
	signal(SIGPROF, ft_print_kill);
	signal(SIGUSR1, ft_print_kill);
	signal(SIGUSR2, ft_print_kill);
	signal(SIGQUIT, ft_print_core);
	signal(SIGILL, ft_print_core);
	signal(SIGTRAP, ft_print_core);
	signal(SIGABRT, ft_print_core);
	signal(SIGEMT, ft_print_core);
	signal(SIGFPE, ft_print_core);
	signal(SIGBUS, ft_print_core);
	signal(SIGSEGV, ft_print_core);
	signal(SIGSYS, ft_print_core);
	signal(SIGURG, ft_print_stop);
	signal(SIGCONT, ft_print_stop);
	signal(SIGCHLD, ft_print_stop);
	signal(SIGIO, ft_print_stop);
}

void	ft_signal_2(void)
{
	signal(SIGWINCH, ft_print_stop);
	signal(SIGINFO, ft_print_stop);
	signal(SIGSTOP, ft_print_discard);
	signal(SIGTSTP, ft_print_discard);
	signal(SIGTTIN, ft_print_discard);
	signal(SIGTTOU, ft_print_discard);
}

void	ft_signal_init(void)
{
	ft_signal();
	ft_signal_2();
}
