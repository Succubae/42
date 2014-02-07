/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:01:27 by rgary             #+#    #+#             */
/*   Updated: 2014/02/01 19:23:10 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	f_ld(t_dat *dat, t_proc *proc)
{
	long	vals[3];

	get_params(dat, proc, vals, DIR_SIZE);
	if (vals[1] > 0 && vals[1] <= REG_NUMBER)
	{
		if (dat->verbose)
			ft_printf(V_LD, (int)vals[0], vals[1]);
		write_long_to_mem(vals[0], proc->reg + ((vals[1]) * REG_SIZE) - 1,
						REG_SIZE);
		if (vals[0] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	move_pc(proc, DIR_SIZE);
}
