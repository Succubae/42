/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 12:24:22 by rgary             #+#    #+#             */
/*   Updated: 2013/12/27 15:41:41 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

t_sort	*ft_swap_a_and_b(t_sort *lnk)
{
	t_sort	*tmp;
	t_sort	*tmp2;

	if (lnk->next != NULL)
	{
		tmp = lnk;
		tmp2 = lnk->next;
		tmp->next = lnk->next->next;
		tmp2->next = tmp;
		lnk = tmp2;
	}
	return (lnk);
}

int		ft_swap_both(t_sort **lnk, t_sort **lnk_b, t_state *state)
{
	char	*op= "ss";

	if ((*lnk))
		(*lnk) = ft_swap_a_and_b((*lnk));
	if ((*lnk_b))
		(*lnk_b) = ft_swap_a_and_b((*lnk_b));
	state->op = ft_add_operation(state->op, op);
	if (ft_update_state(state, (*lnk), (*lnk_b), 8) == 0)
		return (0);
	return (1);
}
