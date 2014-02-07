/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate_on_both.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:06:10 by rgary             #+#    #+#             */
/*   Updated: 2013/12/27 15:04:03 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

t_sort	*ft_rotate_a_and_b(t_sort *lnk)
{
    t_sort  *tmp;
    t_sort  *tmp_move;

    tmp = lnk->next;
    tmp_move = lnk;
    while (lnk->next != NULL)
        lnk = lnk->next;
    tmp_move->next = NULL;
    lnk->next = tmp_move;
    lnk = tmp;
	return (lnk);
}

int		ft_rotate_both(t_sort **lnk, t_sort **lnk_b, t_state *state)
{
	char    *op= "rr";

	FP("\n\nROT BOTH\n\n\n");
	if ((*lnk))
		(*lnk) = ft_rotate_a_and_b((*lnk));
	if ((*lnk_b))
		(*lnk_b) = ft_rotate_a_and_b((*lnk_b));
	state->op = ft_add_operation(state->op, op);
    if (ft_update_state(state, (*lnk), (*lnk_b), 9) == 0)
        return (0);
    return (1);
}

t_sort	*ft_rotate_rev_a_and_b(t_sort *lnk)
{
    t_sort  *tmp;
    t_sort  *tmp2;

    tmp = lnk;
    while (lnk->next != NULL)
    {
        tmp2 = lnk;
        lnk = lnk->next;
    }
    tmp2->next = NULL;
    lnk->next = tmp;
	return (lnk);
}

int		ft_rotate_rev_both(t_sort **lnk, t_sort **lnk_b, t_state *state)
{
	char    *op= "rrr";

	FP("\n\nROT REV BOTH\n\n\n");
	if ((*lnk))
		(*lnk) = ft_rotate_rev_a_and_b((*lnk));
	if ((*lnk_b))
		(*lnk_b) = ft_rotate_rev_a_and_b((*lnk_b));
	state->op = ft_add_operation(state->op, op);
    if (ft_update_state(state, (*lnk), (*lnk_b), 10) == 0)
        return (0);
    return (1);
}
