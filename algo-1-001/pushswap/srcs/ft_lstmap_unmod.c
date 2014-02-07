/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_unmod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:29:42 by rgary             #+#    #+#             */
/*   Updated: 2013/12/27 12:29:02 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "pushswap.h"

int     ft_sortlstcount(t_sort *lst)
{
    int     i;

    i = 0;
    if (lst != NULL)
    {
        i = 1;
        while (lst->next)
        {
            lst = lst->next;
            i++;
        }
    }
    return (i);
}

t_sort	*ft_new_sortlnk(int i)
{
	t_sort	*new;

	new = (t_sort*)malloc(sizeof(t_sort));
	new->val = i;
	new->next = NULL;
	return (new);
}

t_sort	*ft_lstmap_unmod(t_sort *lst)
{
	int		i;
	int		j;
	t_sort	*new;
	t_sort	**tab;

	j = 0;
	i = ft_sortlstcount(lst);
	if (!(tab = (t_sort**)malloc(sizeof(t_sort*) * i + 1)))
		return (NULL);
	tab[i + 1] = NULL;
	while (i > 0)
	{
		new = ft_new_sortlnk(lst->val);
		tab[j] = new;
		if (j > 0)
			tab[j - 1]->next = new;
		lst = lst->next;
		j++;
		i--;
	}
	return (tab[0]);
}
