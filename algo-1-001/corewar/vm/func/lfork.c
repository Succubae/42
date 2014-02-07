/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 11:15:38 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/02 09:32:43 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	f_lfork(t_dat *dat, t_proc *proc)
{
	t_proc	*forked;
	long	param;

	if ((forked = (t_proc *)ft_memalloc(sizeof(t_proc))) == NULL)
		impossible_malloc("t_proc in f_lfork");
	param = get_val(dat->arena, proc->pc + 1, IND_SIZE);
	param = get_true_val(param, 0, IND_SIZE);
	ft_memcpy(forked, proc, sizeof(t_proc));
	forked->pc = (proc->pc + param) % MEM_SIZE;
	forked->cycle_to_exec = -1;
	forked->nbr_live = 0;
	forked->next = *(dat->bgn_lst);
	*(dat->bgn_lst) = forked;
	if (dat->verbose)
		ft_printf(V_LFORK, (int)param, proc->pc, forked->pc);
	proc->pc = (proc->pc + 3) % MEM_SIZE;
}
