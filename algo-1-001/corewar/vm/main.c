/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 18:19:27 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/02 09:28:12 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include "ftprintf.h"
#include "corewar.h"

int		new_proc(t_proc **bgn_lst, long r1, int pc)
{
	t_proc	*new;

	if ((new = (t_proc *)malloc(sizeof(t_proc))) == NULL)
		return (CORE_FAILURE);
	write_long_to_mem(r1, new->reg + REG_SIZE - 1, REG_SIZE);
	new->pc = pc;
	new->carry = 0;
	new->cycle_to_exec = -1;
	new->nbr_live = 0;
	new->next = *bgn_lst;
	*bgn_lst = new;
	return (CORE_SUCCESS);
}

t_dat	*set_data(t_lex *lex)
{
	t_dat	*d;

	if ((d = (t_dat *)malloc(sizeof(t_dat))) == NULL)
		return (NULL);
	if ((d->bgn_lst = (t_proc **)malloc(sizeof(t_proc *))) == NULL)
		return (NULL);
	*(d->bgn_lst) = NULL;
	d->dump = NO_DUMP;
	d->cycle_to_die = CYCLE_TO_DIE;
	d->do_we_check = CYCLE_TO_DIE;
	d->nb_checks = 0;
	d->verbose = 0;
	d->current_cycle = 0;
	d->last_player_alive = -1;
	while (lex)
	{
		if (lex->token == VERBOSE)
			d->verbose = 1;
		if (lex->token == DUMP)
			d->dump = ft_atoi(lex->value);
		lex = lex->next;
	}
	return (d);
}

int		main(int ac, char **ag)
{
	t_lex	*lex;
	t_dat	*d;

	(void)ac;
	lex = NULL;
	lexer_parser(&lex, ag);
	if (lex == NULL)
		prt_err_usage();
	if (lex_checksyntax(lex) == CORE_SUCCESS)
	{
		if ((d = set_data(lex)) == NULL)
			return (prt_err("corewar: set_data: Malloc error.", ""));
		if (load_heroes(d, lex, d->bgn_lst) == CORE_FAILURE)
			return (1);
		cycling_machine(d);
	}
	return (0);
}
