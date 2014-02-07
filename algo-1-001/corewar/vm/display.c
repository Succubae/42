/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 15:25:11 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/01 15:25:12 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		dump(t_dat *d)
{
	int				i;
	unsigned char	*tmp;
	unsigned char	c;

	i = 0;
	tmp = d->arena;
	while (i < MEM_SIZE)
	{
		if (((i % 32) == 0) && (i != 0))
			write(1, "\n", 1);
		c = (tmp[i] >> 4) & 0x0f;
		c = (c > 9 ? c + 'a' - 10 : c + '0');
		write(1, &c, 1);
		c = tmp[i] & 0x0f;
		c = (c > 9 ? c + 'a' - 10 : c + '0');
		write(1, &c, 1);
		i += 1;
		if ((i % 64) != 0 && (i % 2) == 0)
			write(1, " ", 1);
	}
	return (CORE_SUCCESS);
}

void	display_winner(t_dat *d)
{
	t_hero	*tmp;

	if (d->last_player_alive != -1)
	{
		tmp = d->hero_lst;
		while (tmp)
		{
			if (tmp->hero_num == d->last_player_alive)
			{
				ft_printf(HERO_WIN, tmp->hero_num, tmp->name);
				break ;
			}
			tmp = tmp->next;
		}
	}
	else
		ft_putstr_fd("No player found alive ?\n", 2);
}