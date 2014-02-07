/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 15:12:19 by rgary             #+#    #+#             */
/*   Updated: 2013/12/27 15:52:34 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

t_sort	*ft_sort_recurs(t_sort *start, t_sort *end)
{
    t_sort  *newstart;
    t_sort  *newend;
    t_sort  *middle;
	t_sort	*tmp;

    newstart = newend = NULL;
    if (start == NULL || start == end)
        return (start);
    middle = ft_separate(start, end, &newstart, &newend);
	if (newstart != middle)
	{
		tmp = newstart;
		while (tmp->next != middle)
			tmp = tmp->next;
		tmp->next = NULL;
		newstart = ft_sort_recurs(newstart, tmp);
		tmp = ft_get_last(newstart);
		tmp->next = middle;
	}
	middle->next = ft_sort_recurs(middle->next, newend);
	return (newstart);
}

void	ft_move_to_last(t_sort **current, t_sort **last, t_sort **prev)
{
	t_sort	*tmp;

	if ((*prev) != NULL)
		(*prev)->next = (*current)->next;
	tmp = (*current)->next;
	(*current)->next = NULL;
	(*last)->next = (*current);
	(*last) = (*current);
	(*current) = tmp;
}

t_sort	*ft_separate(t_sort *start, t_sort *end, t_sort **newstart, t_sort **newend)
{
	t_sort	*middle;
	t_sort	*prev;
	t_sort	*current;
	t_sort	*last;

	middle = end;
	prev = NULL;
	current = start;
	last = middle;
	while (current != middle)
	{
		if (current->val < middle->val)
		{
			if ((*newstart) == NULL)
				(*newstart) = current;
			prev = current;
			current = current->next;
		}
		else
			ft_move_to_last(&current, &last, &prev);
	}
	if ((*newstart) == NULL)
		(*newstart) = middle;
	(*newend) = last;
	return (middle);
}

t_sort	*ft_get_last(t_sort *lnk)
{
	t_sort	*last;
	t_sort	*save;

	save = lnk;
	while (lnk->next != NULL)
		lnk = lnk->next;
	last = lnk;
	lnk = save;
	return (last);
}

void	ft_sort(t_sort **lnk)
{
	(*lnk) = ft_sort_recurs(*lnk, ft_get_last(*lnk));
}
