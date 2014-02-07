/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ima_fruiiiiiiit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 15:31:06 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/02 13:29:28 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_proc_lst(t_proc **lst)
{
	t_proc	*tmp;
	t_proc	**tmp2;

	tmp2 = lst;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	free(tmp2);
}

void	free_hero_lst(t_hero *lst)
{
	t_hero	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->buf);
		free(tmp->name);
		free(tmp);
	}
}

void	free_data(t_dat *d)
{
	free_proc_lst(d->bgn_lst);
	free_hero_lst(d->hero_lst);
	free(d);
}
