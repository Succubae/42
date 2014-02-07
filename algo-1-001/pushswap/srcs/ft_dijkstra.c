/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dijkstra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:47:33 by rgary             #+#    #+#             */
/*   Updated: 2013/12/28 10:42:46 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "pushswap.h"

t_sort_head	*ft_create_tsorthead_struct(t_sort *unsorted)
{
	t_sort_head	*new;

	new = (t_sort_head*)malloc(sizeof(t_sort_head));
	new->head = unsorted;
	new->next = NULL;
	return (new);
}

t_state		*ft_create_state_struct(t_sort *lnk, t_sort *unsort, t_state *s)
{
	if (s == NULL)
		s = (t_state*)malloc(sizeof(t_state));
	s->list = ft_create_tsorthead_struct(unsort);
	s->list_b = ft_create_tsorthead_struct(NULL);
	s->obj = lnk;
	s->op = NULL;
	return (s);	
}

int			ft_compare_lists(t_sort *lnk, t_sort *lnk2)
{
	int		i;
	t_sort	*save;
	t_sort	*save2;

	i = -1;
	save = lnk;
	save2 = lnk2;
/*	FP("------COMPARE LIST-------\n");
	ft_print_list(lnk, lnk2);*/
	if (!lnk && !lnk2)
		return (0);
	if (!lnk || !lnk2)
		return (1);
	else if (!lnk->val && !lnk2->val)
		return (1);
	while (lnk != NULL && lnk2 != NULL)
	{
		if (lnk->val != lnk2->val)
			break ;
		lnk = lnk->next;
		lnk2 = lnk2->next;
	}
	if (lnk == NULL && lnk2 == NULL)
		i = 0;
	else
		i = 1;
	lnk = save;
	lnk2 = save2;
	return (i);
}

char		*ft_add_operation(char *oldop, char *curop)
{
	int		i;
	int		j;
	int		l;
	char	*newop;

	i = j = l = 0;
	j = -1;
	if (oldop != NULL)
		l = ft_strlen(oldop) + ft_strlen(curop) + 2;
	else
		l = ft_strlen(curop) + 1;
	newop = (char*)malloc(sizeof(char) * l);
	if (oldop != NULL)
	{
		i = -1;
		while (oldop[++i] != '\0')
			newop[i] = oldop[i];
		newop[i] = ' ';
	}
	while (curop[++j] != '\0')
		newop[i + j] = curop[j];
	newop[i + j] = '\0';
	return (newop);
}

void		ft_call_f(t_sort *lnk, t_sort *unsort, t_sort *lnk_b, t_state *st)
{
	int		i;
	int		j;
	t_sort	*new;
	FUNCTAB;
/*	t_func	*functions[11] = {ft_swap_a, ft_swap_b, ft_pick_b_to_a,		\
							  ft_pick_a_to_b, ft_rotate_a, ft_rotate_b,\
							  ft_rotate_rev_a, ft_rotate_rev_b, ft_swap_both,\
							  ft_rotate_both, ft_rotate_rev_both};*/

	i = 0;
	j = 1987987;
	if (st == NULL)
		st = ft_create_state_struct(lnk, new, st);
	while (i < 11)
	{
		FP("J entre souvent ici ?");
		lnk_b = ft_create_empty(lnk_b);
		new = ft_lstmap_unmod(unsort);
		st->op = NULL;
		j = g_funct[i](&new, &lnk_b, st);
		FP("\n\n\n-------------------------------------J = %d----------------------\n\n\n", j);
		if (j == 0)
			break ;
		i++;
	}
}
