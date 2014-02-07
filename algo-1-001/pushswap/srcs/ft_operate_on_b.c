/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate_on_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 13:57:24 by rgary             #+#    #+#             */
/*   Updated: 2013/12/28 10:33:57 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int		ft_swap_b(t_sort **lnk, t_sort **lnk_b, t_state *state)
{
	char    *op= "sb";
	t_sort	*tmp;
	t_sort	*tmp2;

	FP("\nSWAP B\n\n");
	FP("PRE-OP\n");
	ft_print_list((*lnk), (*lnk_b));
	if ((*lnk_b) != NULL && (*lnk_b)->next != NULL)
	{
		tmp = (*lnk_b);
		tmp2 = (*lnk_b)->next;
		tmp->next = (*lnk_b)->next->next;
		tmp2->next = tmp;
		(*lnk_b) = tmp2;
	}
    state->op = ft_add_operation(state->op, op);
    FP("\nPOST-OP\n");
    ft_print_list((*lnk), (*lnk_b));
    if (ft_update_state(state, (*lnk), (*lnk_b), 1) == 0)
		return (0);
    return (1);
}

int		ft_pick_a_to_b(t_sort **lnk, t_sort **lnk_b, t_state *state)
{
	char    *op= "pb";
	t_sort	*tmp;

	FP("\nPICK A TO B\n\n");
	FP("PRE-OP\n");
	ft_print_list((*lnk), (*lnk_b));
	if (lnk != NULL)
	{
		tmp = (*lnk)->next;
		FP("tmp->val = %d\n", tmp->val);
		(*lnk)->next = (*lnk_b);
		(*lnk_b) = (*lnk);
		(*lnk) = tmp;
	}
	state->op = ft_add_operation(state->op, op);
    FP("\nPOST-OP\n");
    ft_print_list((*lnk), (*lnk_b));
    if (ft_update_state(state, (*lnk), (*lnk_b), 3) == 0)
		return (0);
    return (1);
}

int		ft_rotate_b(t_sort **lnk, t_sort **lnk_b, t_state *state)
{
	char    *op= "rb";
	t_sort	*tmp;
	t_sort	*tmp_move;

	FP("\nROT B\n\n");
	FP("lnk_b = %p\n", (void*)(*lnk_b));
	if ((*lnk_b) != NULL && (*lnk_b)->next != NULL)
	{
		tmp = (*lnk_b)->next;
		tmp_move = (*lnk_b);
		while ((*lnk_b)->next != NULL)
			(*lnk_b) = (*lnk_b)->next;
		tmp_move->next = NULL;
		(*lnk_b)->next = tmp_move;
		(*lnk_b) = tmp;
		state->op = ft_add_operation(state->op, op);
		if (ft_update_state(state, (*lnk), (*lnk_b), 5) == 0)
			return (0);
	}
    return (1);
}

int		ft_rotate_rev_b(t_sort **lnk, t_sort **lnk_b, t_state *state)
{
	char    *op= "rrb";
	t_sort	*tmp;
	t_sort	*tmp2;

	FP("ROT REV B\n");
	tmp = (*lnk_b);
	if ((*lnk_b) != NULL && (*lnk_b)->next != NULL)
	{
		while ((*lnk_b)->next != NULL)
		{
			tmp2 = (*lnk_b);
			(*lnk_b) = (*lnk_b)->next;
		}
		tmp2->next = NULL;
		(*lnk_b)->next = tmp;
		state->op = ft_add_operation(state->op, op);
		if (ft_update_state(state, (*lnk), (*lnk_b), 7) == 0)
			return (0);
	}
    return (1);
}
