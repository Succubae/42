/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 14:53:15 by rgary             #+#    #+#             */
/*   Updated: 2014/02/02 14:53:18 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	f_ldi_exec(t_dat *dat, t_proc *proc, short type[2], long vals[3])
{
	type[0] = (type[0] == DIR_CODE ? IND_SIZE : REG_SIZE);
	type[1] = (type[1] == DIR_CODE ? IND_SIZE : REG_SIZE);
	vals[0] = get_true_val(vals[0], 0, type[0]);
	vals[1] = get_true_val(vals[1], 0, type[1]);
	vals[0] = (vals[0] + vals[1]) % MEM_SIZE;
	vals[0] = get_val(dat->arena, proc->pc + vals[0], REG_SIZE);
	if (dat->verbose)
		ft_printf(V_LDI, (int)vals[0], vals[2]);
	write_long_to_mem(vals[0], proc->reg + (vals[2] * REG_SIZE) - 1, REG_SIZE);
}

void	f_ldi(t_dat *dat, t_proc *proc)
{
	long	vals[3];
	short   type[2];
	int		err;

	err = 0;
	type[0] = ((proc->params >> 6) % 4);
	type[1] = ((proc->params >> 4) % 4);
	get_params(dat, proc, vals, IND_SIZE);
	if (vals[2] > 0 && vals[2] <= REG_NUMBER)
	{
		if (type[0] == REG_CODE && vals[0] > 0 && vals[0] <= REG_NUMBER)
			vals[0] = get_val(REG(vals[0]), 0, REG_SIZE);
		else if (type[0] == REG_CODE)
			err = 1;
		if (type[1] == REG_CODE && vals[1] > 0 && vals[1] <= REG_NUMBER)
			vals[1] = get_val(REG(vals[1]), 0, REG_SIZE);
		else if (type[1] == REG_CODE)
			err = 1;
		if (!err)
			f_ldi_exec(dat, proc, type, vals);
	}
	move_pc(proc, IND_SIZE);
}
