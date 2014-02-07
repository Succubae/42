/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 12:33:38 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 14:07:29 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh1.h"

char	*retrieve_prompt(char *prompt);
void	print_prompt(char *prompt);

void	ft_print_discard(int i)
{
	char	*s;

	(void)i;
	FP2("\033[31mReceived \"discard signal\" signal\033[0m\n", 2);
	s = retrieve_prompt(NULL);
	print_prompt(s);
}

void	ft_print_stop(int i)
{
	(void)i;
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
	char	*s;

	s = NULL;
	(void)i;
	FP2("\033[31mReceived terminate process signal\033[0m\n", 2);
	if (i == 2)
	{
		s = retrieve_prompt(NULL);
		print_prompt(s);
	}
}
