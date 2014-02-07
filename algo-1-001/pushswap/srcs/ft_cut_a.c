/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 12:41:07 by rgary             #+#    #+#             */
/*   Updated: 2013/12/26 13:02:11 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

t_sort	*ft_cut_a(t_sort *lnk, t_sort *lnk_b)
{
	int		i;
	int		j;
	t_sort	*save;
	t_sort	*tmp;

	i = j = 0;
	save = lnk;
	while (i++, lnk != NULL)
		lnk = lnk->next;
	lnk = save;
	while (j < (i / 2))
	{
		tmp = lnk;
		lnk = lnk->next;
		j++;
	}
	tmp->next = NULL;
	lnk_b = lnk;
	return (lnk_b);
}
