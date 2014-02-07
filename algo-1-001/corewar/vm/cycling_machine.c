/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycling_machine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 14:41:50 by sbuono            #+#    #+#             */
/*   Updated: 2014/02/02 14:59:56 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ftprintf.h"
#include "corewar.h"

void	load_instruction(t_dat *d, t_proc *proc)
{
	t_ui	wait_cyc[17] = {0, 10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800
							, 10, 50, 1000, 2};

	if ((d->arena)[proc->pc] == 0 || (d->arena)[proc->pc] > 16)
	{
		proc->cycle_to_exec = 0;
		proc->pc = (proc->pc + 1) % MEM_SIZE;
	}
	else
	{
		proc->cycle_to_exec = wait_cyc[(d->arena)[proc->pc]] - 1;
		proc->instruct = (d->arena)[proc->pc];
		proc->params = (d->arena)[proc->pc + 1];
	}
}

int		process_cycle(t_dat *d)
{
	ft_inst		*tab[17] = {NULL, f_live, f_ld, f_st, f_add, f_sub, f_and, \
							f_or, f_xor, f_zjmp, f_ldi, f_sti, f_fork, f_lld, \
							f_lldi, f_lfork, f_aff};
	t_proc	*tmp;

	tmp = *(d->bgn_lst);
	while (tmp)
	{
		if (tmp->cycle_to_exec == LOAD_NEW_INSTRUCT)
			load_instruction(d, tmp);
		else if (tmp->cycle_to_exec == EXECUTE_INSTRUCT)
			(tab[tmp->instruct])(d, tmp);
		(tmp->cycle_to_exec)--;
		tmp = tmp->next;
	}
	return (CORE_SUCCESS);
}

void	change_cycle_to_die(t_dat *d, t_proc *p_lst)
{
	int	nbr_live;

	nbr_live = 0;
	while (p_lst)
	{
		nbr_live += (p_lst->nbr_live);
		p_lst = p_lst->next;
	}
	if (nbr_live >= NBR_LIVE || d->nb_checks == MAX_CHECKS)
	{
		d->cycle_to_die = d->cycle_to_die - CYCLE_DELTA;
		d->cycle_to_die = (d->cycle_to_die < 1 ? 1 : d->cycle_to_die);
		d->do_we_check = d->do_we_check + d->cycle_to_die;
		d->nb_checks = 0;
	}
	else
	{
		d->do_we_check = d->do_we_check + d->cycle_to_die;
		(d->nb_checks)++;
	}
}

int		check_champions(t_dat *d, t_proc **bgn_lst)
{
	t_proc	*tmp;
	int		proc[2] = {0, 0};

	change_cycle_to_die(d, *bgn_lst);
	while (*bgn_lst)
	{
		proc[0] += 1;
		if ((*bgn_lst)->nbr_live == 0)
		{
			tmp = *bgn_lst;
			*bgn_lst = (*bgn_lst)->next;
			proc[1] += 1;
			free(tmp);
		}
		else
		{
			(*bgn_lst)->nbr_live = 0;
			bgn_lst = &((*bgn_lst)->next);
		}
	}
	if (d->verbose)
		ft_printf(V_KILLED, proc[1], proc[0] - proc[1]);
	if (*(d->bgn_lst) == NULL)
		return (END_OF_WAR);
	return (0);
}

int		cycling_machine(t_dat *d)
{
	int		counter;
	int		end;

	counter = end = 0;
	while (end != END_OF_WAR)
	{
		if ((d->dump)-- == 0)
			return (dump(d));
		process_cycle(d);
		if (counter == d->do_we_check)
			end = check_champions(d, d->bgn_lst);
		counter++;
	}
	display_winner(d);
	free_data(d);
	return (CORE_SUCCESS);
}
