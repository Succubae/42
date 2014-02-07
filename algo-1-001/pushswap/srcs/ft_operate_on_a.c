/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate_on_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 13:16:29 by rgary             #+#    #+#             */
/*   Updated: 2013/12/28 10:33:40 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int		ft_swap_a(t_sort **lnk, t_sort **lnk_b, t_state *state)
{
	char	*op = "sa";
	t_sort	*tmp;
	t_sort	*tmp2;

	FP("\nSWAP A\n\n");
	FP("PRE-OP\n");
	ft_print_list((*lnk), (*lnk_b));
	FP("state = %p\n", (void*)state->list);
	FP("state val = %p\n", (void*)state->list->head);
	FP("lnk = %d\n", (*lnk)->val);
	tmp = (*lnk);
	tmp2 = (*lnk)->next;
	tmp->next = (*lnk)->next->next;
	tmp2->next = tmp;
	(*lnk) = tmp2;
	state->op = ft_add_operation(state->op, op);
	FP("\nPOST-OP\n");
    ft_print_list((*lnk), (*lnk_b));
	return (ft_update_state(state, (*lnk), (*lnk_b), 0));
}

int		ft_pick_b_to_a(t_sort **lnk, t_sort **lnk_b, t_state *state)
{
	char    *op= "pa";
	t_sort	*tmp;

	FP("\nPICK B TO A\n\n");
	FP("PRE-OP\n");
	ft_print_list((*lnk), (*lnk_b));
	if ((*lnk_b) != NULL)
	{
		tmp = (*lnk_b)->next;
		(*lnk_b)->next = (*lnk);
		(*lnk) = (*lnk_b);
		(*lnk_b) = tmp;
	}
    state->op = ft_add_operation(state->op, op);
    FP("\nPOST-OP\n");
    ft_print_list((*lnk), (*lnk_b));
    if (ft_update_state(state, (*lnk), (*lnk_b), 2) == 0)
		return (0);
    return (1);
}

int		ft_rotate_a(t_sort **lnk, t_sort **lnk_b, t_state *state)
{
	char    *op= "ra";
	t_sort	*tmp;
	t_sort	*tmp_move;

	FP("\n\nROT A\n\n\n");
	FP("PRE-OP\n");
	ft_print_list((*lnk), (*lnk_b));
	tmp = (*lnk)->next;
	tmp_move = (*lnk);
	while ((*lnk)->next != NULL)
		(*lnk) = (*lnk)->next;
	tmp_move->next = NULL;
	(*lnk)->next = tmp_move;
	(*lnk) = tmp;
    state->op = ft_add_operation(state->op, op);
    FP("\nPOST-OP\n");
    ft_print_list((*lnk), (*lnk_b));
    if (ft_update_state(state, (*lnk), (*lnk_b), 4) == 0)
		return (0);
    return (1);
}

int		ft_rotate_rev_a(t_sort **lnk, t_sort **lnk_b, t_state *state)
{
	char    *op= "rra";
	t_sort	*tmp;
	t_sort	*tmp2;

	FP("ROT REV A\n");
	FP("PRE-OP\n");
    ft_print_list((*lnk), (*lnk_b));
	tmp = (*lnk);
	while ((*lnk)->next != NULL)
	{
		tmp2 = (*lnk);
		(*lnk) = (*lnk)->next;
	}
	tmp2->next = NULL;
	(*lnk)->next = tmp;
    state->op = ft_add_operation(state->op, op);
    FP("\nPOST-OP\n");
    ft_print_list((*lnk), (*lnk_b));
    if (ft_update_state(state, (*lnk), (*lnk_b), 6) == 0)
		return (0);
    return (1);
}
