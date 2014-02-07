/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 12:29:13 by rgary             #+#    #+#             */
/*   Updated: 2014/02/01 17:52:15 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	handle_verbose(long params[3])
{
	ft_printf(V_XOR , params[0], params[1], params[2]);
}

void		f_xor(t_dat *dat, t_proc *proc)
{
	long	params[3];
	long	res;
	short	tp[2];
	t_uc	*dest;

	get_params(dat, proc, params, DIR_SIZE);
	tp[0] = ((proc->params >> (3 * 2)) % 4);
	tp[1] = ((proc->params >> ((3 - 1) * 2)) % 4);
	if (isreg(params[2]))
	{
		if (tp[0] == REG_CODE && isreg(params[0]))
			params[0] = get_val(REG(params[0]), 0, REG_SIZE);
		if (tp[1] == REG_CODE && isreg(params[1]))
			params[1] = get_val(REG(params[1]), 0, REG_SIZE);
		res = params[0] ^ params[1];
		if (dat->verbose)
			handle_verbose(params);
		dest = proc->reg + ((params[2] * REG_SIZE) - 1);
		write_long_to_mem(res, dest, REG_SIZE);
		proc->carry = (res == 0 ? 1 : 0);
	}
	move_pc(proc, DIR_SIZE);
}
