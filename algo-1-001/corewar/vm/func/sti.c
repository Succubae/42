/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 18:02:21 by rgary             #+#    #+#             */
/*   Updated: 2014/02/02 09:14:21 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	f_sti_exec(t_dat *dat, t_proc *proc, short type[2], long val[3])
{
	int	val_res;

	type[0] = (type[0] == DIR_CODE ? IND_SIZE : REG_SIZE);
	type[1] = (type[1] == DIR_CODE ? IND_SIZE : REG_SIZE);
	val[1] = get_true_val(val[1], 0, type[0]);
	val[2] = get_true_val(val[2], 0, type[1]);
	val[1] = (val[1] + val[2]) % MEM_SIZE;
	if (val[1] >= (MEM_SIZE / 2))
		val[1] = MEM_SIZE - ((MEM_SIZE - val[1]) % IDX_MOD);
	else
		val[1] = val[1] % IDX_MOD;
	if (dat->verbose)
	{
		val_res = (int)get_val(REG(val[0]), 0, REG_SIZE);
		ft_printf(V_STI, val_res, val[1] + proc->pc);
	}
	cpy_to_arena(REG(val[0]), dat, proc->pc + val[1], REG_SIZE);
}

void	f_sti(t_dat *dat, t_proc *proc)
{
	long	val[3];
	short	type[2];
	int		err;

	err = 0;
	type[0] = ((proc->params >> ((3 - 1) * 2)) % 4);
	type[1] = ((proc->params >> ((3 - 2) * 2)) % 4);
	get_params(dat, proc, val, IND_SIZE);
	if (val[0] > 0 && val[0] <= REG_SIZE)
	{
		if (type[0] == REG_CODE && val[1] > 0 && val[1] <= REG_NUMBER)
			val[1] = get_val(REG(val[1]), 0, REG_SIZE);
		else if (type[0] == REG_CODE)
			err = 1;
		if (type[1] == REG_CODE && val[2] > 0 && val[2] <= REG_NUMBER)
			val[2] = get_val(REG(val[2]), 0, REG_SIZE);
		else if (type[1] == REG_CODE)
			err = 1;
		if (!err)
			f_sti_exec(dat, proc, type, val);
	}
	move_pc(proc, IND_SIZE);
}
