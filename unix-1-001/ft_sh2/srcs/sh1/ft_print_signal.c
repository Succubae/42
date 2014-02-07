/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 12:33:38 by rgary             #+#    #+#             */
/*   Updated: 2014/01/25 10:53:55 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh1.h"

void	ft_print_discard(int i)
{
	FP("\033[31mReceived \"discard signal\" signal: %d\033[0m\n", i);
}

void	ft_print_stop(int i)
{
	if (i != SIGCHLD && i != SIGWINCH)
		FP("\033[31mReceived stop process signal: %d\033[0m\n", i);
}

void	ft_print_core(int i)
{
	if (i == 11)
	{
		FP2("\033[31mReceived core dump signal: ", 2);
		FP2("Segmentation Fault", 2);
		FP2("\033[0m\n", 2);
	}
	else
	{
		FP2("\033[31mReceived core dump signal: ", 2);
		FP2(ft_itoa(i), 2);
		FP2("\033[0m\n", 2);
	}
	exit(-1);
}

void	ft_print_kill(int i)
{
	FP("\033[31mReceived terminate process signal: %d\033[0m\n", i);
}
