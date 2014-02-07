/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:30:21 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/02 09:58:32 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	f_fork(t_dat *dat, t_proc *proc)
{
	t_proc	*forked;
	long	param;

	if ((forked = (t_proc *)ft_memalloc(sizeof(t_proc))) == NULL)
		impossible_malloc("t_proc in f_fork");
	param = get_val(dat->arena, proc->pc + 1, IND_SIZE);
	param = get_true_val(param, 1, IND_SIZE);
	ft_memcpy(forked, proc, sizeof(t_proc));
	forked->pc = (proc->pc + param) % MEM_SIZE;
	forked->cycle_to_exec = -1;
	forked->nbr_live = 0;
	forked->next = *(dat->bgn_lst);
	*(dat->bgn_lst) = forked;
	if (dat->verbose)
	{
		if (param > (MEM_SIZE / 2))
			param = param - MEM_SIZE;
		ft_printf(V_FORK, param, proc->pc, forked->pc);
	}
	proc->pc = (proc->pc + 3) % MEM_SIZE;
}
