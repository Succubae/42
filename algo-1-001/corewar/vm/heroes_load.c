/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heroes_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 15:27:42 by sbuono            #+#    #+#             */
/*   Updated: 2014/02/02 13:27:00 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_hero	*new_hero(int hero_num, char *path)
{
	int		fd;
	t_hero	*new;

	if ((new = (t_hero *)malloc(sizeof(t_hero))) == NULL)
		return (prt_err_null("new_hero: malloc", ""));
	if ((fd = open(path, O_RDONLY)) == -1)
		return (prt_err_null("new_hero: open", path));
	if (find_prog_size(fd) > CHAMP_MAX_SIZE)
		return (prt_err_null("new_hero: bad size", path));
	if (!check_magic_number(fd))
		return (prt_err_null("new_hero: Invalid magic number", path));
	new->buf = (unsigned char*)ft_strnew(CHAMP_MAX_SIZE);
	new->name = ft_strnew(PROG_NAME_LENGTH + 1);
	lseek(fd, 4, SEEK_SET);
	read(fd, new->name, PROG_NAME_LENGTH);
	lseek(fd, sizeof(header_t), SEEK_SET);
	read(fd, new->buf, CHAMP_MAX_SIZE);
	close(fd);
	new->hero_num = hero_num;
	new->next = NULL;
	free(path);
	return (new);
}

int		get_hero_lst(t_dat *d, t_lex *lex)
{
	int		hero_num;
	char	*hero_path;
	t_lex	*tmp;
	t_hero	*tmp_h;

	tmp = lex;
	hero_path = NULL;
	hero_num = -1;
	while (tmp)
	{
		if (tmp->token == HERO_NUMB)
			hero_num = ft_atoi(tmp->value);
		if (tmp->token == HERO_FILE)
			hero_path = ft_strdup(tmp->value);
		if (hero_path != NULL)
		{
			if ((tmp_h = new_hero(hero_num, hero_path)) == NULL)
				return (CORE_FAILURE);
			hero_push_back(d, tmp_h);
			hero_num = -1;
			hero_path = NULL;
		}
		tmp = tmp->next;
	}
	return (CORE_SUCCESS);
}

void	update_hero_num(t_hero *tmp, t_dat *d)
{
	if (tmp->hero_num == -1)
		tmp->hero_num = next_num_available(d->hero_lst);
}

int		load_heroes(t_dat *d, t_lex *lex, t_proc **bgn_lst)
{
	int		count;
	int		mem;
	t_hero	*tmp;
	void	*addr_to_cpy;

	count = 0;
	mem = MEM_SIZE / tot_nb_of_heroes(lex);
	while (lex->token != HERO_NUMB && lex->token != HERO_FILE)
		lex = lex->next;
	if (get_hero_lst(d, lex) == CORE_FAILURE)
		return (CORE_FAILURE);
	tmp = d->hero_lst;
	while (tmp)
	{
		update_hero_num(tmp, d);
		if (new_proc(bgn_lst, (long)tmp->hero_num, mem * count) == CORE_FAILURE)
			return (CORE_FAILURE);
		addr_to_cpy = d->arena + (mem * count);
		ft_memcpy(addr_to_cpy, tmp->buf, CHAMP_MAX_SIZE);
		tmp = tmp->next;
		count++;
	}
	return (CORE_SUCCESS);
}
