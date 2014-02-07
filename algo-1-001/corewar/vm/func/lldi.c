/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 10:52:28 by rgary             #+#    #+#             */
/*   Updated: 2014/02/01 17:49:57 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	f_lldi(t_dat *dat, t_proc *proc)
{
	long	vals[3];
	long	val;

	get_params(dat, proc, vals, IND_SIZE);
	if (((val = get_addr(proc, vals)) != CORE_FAILURE)
		&& vals[2] > 0 && vals[2] <= REG_NUMBER)
	{
		val = get_true_val(val, 0, IND_SIZE);
		val = get_val(dat->arena, proc->pc + val, REG_SIZE);
		if (dat->verbose)
			ft_printf(V_LLDI, val, vals[2]);
		write_long_to_mem(val, proc->reg + (vals[2] * REG_SIZE) - 1, REG_SIZE);
		proc->carry = (val == 0 ? 1 : 0);
	}
	move_pc(proc, IND_SIZE);
}
