/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:37:37 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/01 19:56:58 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_long_to_mem(long i, t_uc *end_s, int size)
{
	if (size > 1)
		write_long_to_mem((i >> 8), (end_s - 1), (size - 1));
	*end_s = i % 256;
}

long	power_256(int coef)
{
	if (coef == 0)
		return (1);
	return (256 * power_256(--coef));
}

long	get_val(t_uc *mem, int addr, int size)
{
	long	ret;
	int		i;

	ret = 0;
	i = 0;
	size--;
	while (i <= size)
	{
		ret += (mem[(addr + i) % MEM_SIZE] * power_256(size - i));
		i++;
	}
	return (ret);
}

void	get_params(t_dat *d, t_proc *p, long param_val[3], int dir_s)
{
	int		i;
	int		addr;
	int		tmp;
	int		type;

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
			type = get_true_val(type, 1, IND_SIZE);
			param_val[i] = get_val(d->arena
				, p->pc + type, DIR_SIZE);
			addr += IND_SIZE;
		}
	}
}

void	move_pc(t_proc *proc, int dir_s)
{
	int		i;
	int		nb_byte_to_move;
	int		type;

	i = type = 0;
	nb_byte_to_move = 2;
	while (i < 3)
	{
		type = ((proc->params >> ((3 - i) * 2)) % 4);
		if (type == REG_CODE)
			nb_byte_to_move += NB_ENC_REG;
		else if (type == DIR_CODE)
			nb_byte_to_move += dir_s;
		else if (type == IND_CODE)
			nb_byte_to_move += IND_SIZE;
		++i;
	}
	proc->pc = (proc->pc + nb_byte_to_move) % MEM_SIZE;
}
