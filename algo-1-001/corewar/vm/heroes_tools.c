/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heroes_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 16:10:16 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/25 16:10:18 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		tot_nb_of_heroes(t_lex *lex)
{
	int		count;

	count = 0;
	while (lex)
	{
		if (lex->token == HERO_FILE)
			count++;
		lex = lex->next;
	}
	return (count);
}

int		next_num_available(t_hero *lst)
{
	int		num_available;
	t_hero	*tmp;

	num_available = 1;
	tmp = lst;
	while (tmp)
	{
		if (tmp->hero_num == num_available)
		{
			num_available++;
			tmp = lst;
		}
		else
			tmp = tmp->next;
	}
	return (num_available);
}

t_ui	find_prog_size(int fd)
{
	unsigned int	prog_size;
	unsigned char	c[4];

	prog_size = sizeof(int) + PROG_NAME_LENGTH + 1;
	if (((PROG_NAME_LENGTH + 1) % 4) > 0)
		prog_size = prog_size + 4 - ((PROG_NAME_LENGTH + 1) % 4);
	lseek(fd, prog_size, SEEK_SET);
	read(fd, c, 4);
	prog_size = (unsigned int)(c[0] << 24 | c[1] << 16 | c[2] << 8 | c[3]);
	return (prog_size);
}

void	hero_push_back(t_dat *d, t_hero *new)
{
	t_hero			*tmp;

	if (d->hero_lst == NULL)
		d->hero_lst = new;
	else
	{
		tmp = d->hero_lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		check_magic_number(int fd)
{
	t_ui	magic;
	t_uc	c[4];

	lseek(fd, 0, SEEK_SET);
	read(fd, c, 4);
	magic = (unsigned int)(c[0] << 24 | c[1] << 16 | c[2] << 8 | c[3]);
	return (magic == COREWAR_EXEC_MAGIC);
}