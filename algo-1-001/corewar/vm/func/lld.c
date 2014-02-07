/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 09:17:29 by sbuono            #+#    #+#             */
/*   Updated: 2014/02/01 17:18:24 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	f_lld(t_dat *dat, t_proc *proc)
{
	long	param_val[3];
	t_uc	*dest;
	int		dest2;

	get_long_params(dat, proc, param_val, DIR_SIZE);
	if (param_val[1] > 0 && param_val[1] < REG_NUMBER + 1)
	{
		dest = proc->reg + ((param_val[1]) * REG_SIZE) - 1;
		if (dat->verbose)
			ft_printf(V_LLD, param_val[0], param_val[1]);
		write_long_to_mem(param_val[0], dest, REG_SIZE);
		dest2 = (proc->pc + param_val[0]) % MEM_SIZE;
		proc->carry = (get_val(dat->arena, dest2, REG_SIZE) == 0 ? 1 : 0);
	}
	move_pc(proc, DIR_SIZE);
}
