/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 18:17:58 by rgary             #+#    #+#             */
/*   Updated: 2014/02/02 10:16:34 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	f_live(t_dat *dat, t_proc *proc)
{
	long	i;
	t_hero	*save;

	i = get_val(dat->arena, proc->pc + 1, 4);
	save = dat->hero_lst;
	proc->nbr_live += 1;
	while (save != NULL)
	{
		if (save->hero_num == (int)i)
		{
			ft_printf(HERO_ALIVE, save->hero_num, save->name);
			dat->last_player_alive = (int)i;
			break ;
		}
		save = save->next;
	}
	proc->pc += 5;
}
