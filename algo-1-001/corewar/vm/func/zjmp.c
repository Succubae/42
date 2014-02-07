/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:20:22 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/01 19:21:22 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	f_zjmp(t_dat *dat, t_proc *proc)
{
	long	val;

	val = get_val(dat->arena, (proc->pc + 1), IND_SIZE);
	val = get_true_val(val, 1, IND_SIZE);
	if (proc->carry == 1)
	{
		if (dat->verbose)
			ft_printf(V_ZJMP_S1, val, proc->pc);
		proc->pc = (proc->pc + val) % MEM_SIZE;
		if (dat->verbose)
			ft_printf(V_ZJMP_S2, proc->pc);
	}
	else
	{
		if (dat->verbose)
			ft_printf(V_ZJMP_F, val, proc->pc);
		proc->pc += 3;
		proc->pc = proc->pc % MEM_SIZE;
	}
}
