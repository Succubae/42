/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 11:02:58 by rgary             #+#    #+#             */
/*   Updated: 2014/02/01 11:20:05 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_addr(t_proc *proc, long param_val[3])
{
	int		addr;

	if (proc->params >> 6 == REG_CODE)
	{
		if (param_val[0] < 1 || param_val[0] > REG_NUMBER)
			return (CORE_FAILURE);
		addr = (int)get_val(REG(param_val[0]), 0, REG_SIZE);
	}
	else
		addr = get_true_val(param_val[0], 0, REG_SIZE);
	if (((proc->params >> 4) & 0xff) == REG_CODE)
	{
		if (param_val[1] < 1 || param_val[1] > REG_NUMBER)
			return (CORE_FAILURE);
		addr += (int)get_val(REG(param_val[1]), 0, REG_SIZE);
	}
	else
		addr += (int)param_val[1];
	return (addr);
}

void	cpy_to_arena(t_uc *reg, t_dat *d, int addr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_memcpy(d->arena + ((addr + i) % MEM_SIZE), reg + i, 1);
		i++;
	}
}

int		isreg(long param)
{
	if (param > 0 && param <= REG_NUMBER)
		return (1);
	return (0);
}

long	get_true_val(long val, int idx, int size)
{
	long	tmp;

	tmp = power_256(size);
	if (val > (tmp / 2) && idx == 1)
		val = MEM_SIZE - ((tmp - val) % IDX_MOD);
	else if (val > (tmp / 2) && idx == 0)
		val = MEM_SIZE - ((tmp - val) % MEM_SIZE);
	else if (val < (tmp / 2) && idx == 1)
		val = val % IDX_MOD;
	return (val);
}

void	get_long_params(t_dat *d, t_proc *p, long param_val[3], int dir_s)
{
	int	i;
	int	addr;
	int	tmp;
	int	type;

	i = -1;
	addr = p->pc + 2;
	while (++i < 3)
	{
		type = ((p->params >> ((3 - i) * 2)) % 4);
		if (type == REG_CODE || type == DIR_CODE)
		{
			tmp = (type == REG_CODE ? NB_ENC_REG : dir_s);
			param_val[i] = get_val(d->arena, addr, tmp);
			addr += tmp;
		}
		else if (type == IND_CODE)
		{
			type = get_val(d->arena, addr, IND_SIZE);
			type = get_true_val(type, 0, IND_SIZE);
			param_val[i] = get_val(d->arena, p->pc + type, DIR_SIZE);
			addr += IND_SIZE;
		}
	}
}
