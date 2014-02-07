/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:54:40 by rgary             #+#    #+#             */
/*   Updated: 2014/02/01 19:59:09 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	f_add(t_dat *dat, t_proc *proc)
{
	long	i;
	long	j;
	long	k;

	i = (int)get_val(dat->arena, proc->pc + 2, NB_ENC_REG);
	j = (int)get_val(dat->arena, proc->pc + 3, NB_ENC_REG);
	k = (int)get_val(dat->arena, proc->pc + 4, NB_ENC_REG);
	if (i > 0 && i <= REG_NUMBER && j > 0 && j <= REG_NUMBER)
	{
		if (k > 0 && k <= REG_NUMBER)
		{
			i = (int)get_val(REG(i), 0, REG_SIZE);
			j = (int)get_val(REG(j), 0, REG_SIZE);
			if (dat->verbose)
				ft_printf(V_ADD, i, j, k);
			i = i + j;
			write_long_to_mem(i, (proc->reg + ((k * REG_SIZE) - 1)), REG_SIZE);
			proc->carry = (i == 0 ? 1 : 0);
		}
	}
	move_pc(proc, DIR_SIZE);
}
