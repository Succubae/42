/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_list_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 11:56:10 by rgary             #+#    #+#             */
/*   Updated: 2013/12/27 13:47:44 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>
#include "pushswap.h"

t_sort	*ft_sort_push_back(t_sort *lnk, t_sort *new)
{
	t_sort	*save;

	save = lnk;
	if (lnk == NULL)
		return (new);
	while (lnk->next != NULL)
		lnk = lnk->next;
	lnk->next = new;
	return (save);
}

t_sort	*ft_create_empty(t_sort *lnk)
{
	lnk = NULL;
	return (lnk);
}

t_sort	*ft_create_filled_lnk(t_sort *new, int i)
{
	new = (t_sort*)malloc(sizeof(t_sort));
	new->val = i;
	new->next = NULL;
	return (new);
}

t_sort	*ft_build_list_a(t_sort *lnk, char *s)
{
	int		i;
	t_sort	*new;

	i = ft_atoi(s);
	new = NULL;
	new = ft_create_filled_lnk(new, i);
	lnk = ft_sort_push_back(lnk, new);
	return (lnk);
}
