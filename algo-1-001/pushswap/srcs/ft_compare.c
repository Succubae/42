/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 18:39:20 by rgary             #+#    #+#             */
/*   Updated: 2013/12/28 12:08:30 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "pushswap.h"

int		ft_update_state(t_state *state, t_sort *lnk, t_sort *lnk_b, int i)
{
	int			j;
	t_sort_head	*save;
	t_sort_head	*save_b;
	FUNCTAB;

	j = 0;
	(void)i;
	save = state->list;
	while (state->list->next != NULL)
		state->list = state->list->next;
	state->list->next = ft_create_tsorthead_struct(ft_lstmap_unmod(lnk));
	state->list = save;
	save_b = state->list_b;
	while (state->list_b->next != NULL)
		state->list_b = state->list_b->next;
	state->list_b->next = ft_create_tsorthead_struct(ft_lstmap_unmod(lnk_b));
	state->list_b = save_b;
	if (ft_compare_lists(lnk, state->obj) == 0)
	{
		ft_print_operations(state->op);
		exit(1);
	}
	else if (ft_compare_other_states(lnk, lnk_b, state) == -1)
		return (1);
	while (j < 11)
	{
		FP("______j = %d_______\n", j);
		if (j != i)
		{
			if (g_funct[j](&lnk, &lnk_b, state) == 0)
			{
				FP("JE RENTRE DES FOIS ICI ?");
				return (0);
			}
		}
		j++;
	}
	return (1);
}

int		ft_compare_other_states(t_sort *lnk, t_sort *lnk_b, t_state *state)
{
	t_sort_head	*save;
	t_sort_head	*save_b;

	save = state->list;
	save_b = state->list_b;
	while (state->list && state->list_b)
	{
		if (ft_compare_lists(lnk, state->list->head) == 0
			&& ft_compare_lists(lnk_b, state->list_b->head) == 0)
			return (-1);
		state->list = state->list->next;
		state->list_b = state->list_b->next;
	}
	state->list = save;
	state->list_b = save_b;
	return (0);
}
