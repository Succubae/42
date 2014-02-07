/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:26:15 by rgary             #+#    #+#             */
/*   Updated: 2014/02/02 09:44:05 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	handle_verbose(t_proc *proc, short type, long vals[3], long val)
{
	int	val_res;

	type = (proc->pc + val) % MEM_SIZE;
	if (type > (MEM_SIZE / 2))
		type = type - MEM_SIZE;
	val_res = (int)get_val(REG(vals[0]), 0, REG_SIZE);
	ft_printf(V_ST, val_res, type);
}

void		f_st(t_dat *dat, t_proc *proc)
{
	long	vals[3];
	long	val;
	short	type;

	type = ((proc->params >> ((3 - 1) * 2)) % 4);
	get_params(dat, proc, vals, DIR_SIZE);
	if (vals[0] > 0 && vals[0] <= REG_NUMBER)
	{
		if (type == REG_CODE)
			ft_memcpy(REG(vals[1]), REG(vals[0]), REG_SIZE);
		else if (type == IND_CODE)
		{
			val = (get_val(dat->arena, proc->pc + 3, IND_SIZE));
			val = get_true_val(val, 1, IND_SIZE);
			if (dat->verbose)
				handle_verbose(proc, type, vals, val);
			cpy_to_arena(REG(vals[0]), dat, proc->pc + val, REG_SIZE);
		}
	}
	move_pc(proc, DIR_SIZE);
}
