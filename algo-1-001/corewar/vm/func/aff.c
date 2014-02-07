/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:31:03 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/01 17:22:52 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	f_aff(t_dat *dat, t_proc *proc)
{
	int		reg_nb;
	long	val;
	char	dsp;

	reg_nb = get_val(dat->arena, proc->pc + 2, NB_ENC_REG);
	if (reg_nb > 0 && reg_nb <= REG_NUMBER)
	{
		val = get_val(REG(reg_nb), 0, REG_SIZE);
		dsp = val % 256;
		if (dat->verbose)
		{
			write(1, "aff: ", 5);
			write(1, &dsp, 1);
			write(1, "\n", 1);
		}
	}
	proc->pc += 3;
}
