/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:41:28 by rgary             #+#    #+#             */
/*   Updated: 2013/12/03 11:07:16 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	int		i;
	int		j;
	t_list	*new;
	t_list	**tab;

	j = 0;
	i = ft_lstcount(lst);
	if (!(tab = (t_list**)malloc(sizeof(t_list*) * i + 1)))
		return (NULL);
	tab[i + 1] = NULL;
	while (i > 0)
	{
		(*f)(lst);
		new = ft_lstnew(lst->content, lst->content_size);
		tab[j] = new;
		if (j > 0)
			tab[j - 1]->next = new;
		lst = lst->next;
		j++;
		i--;
	}
	return (tab[0]);
}
