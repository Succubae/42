/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 18:39:20 by rgary             #+#    #+#             */
/*   Updated: 2013/12/26 18:53:05 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int		ft_compare_other_states(t_sort *lnk, t_state *state)
{
	t_sort	*save;

	save = state->list;
	while (state->list)
	{
		if (ft_compare_lists(lnk, state->list) == 0)
			return (-1);
		state->list = state->list->next;
	}
	state->list = save;
	return (0);
}
