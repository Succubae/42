/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 10:59:19 by rgary             #+#    #+#             */
/*   Updated: 2013/12/09 11:00:37 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

t_list2	*ft_sort_time(t_list2 *lnk, t_list2 *tmp, t_list2 *tmp2, t_list2 *flnk)
{
	int		cnt;

	cnt = 1;
	if (lnk != NULL && lnk->next != NULL )
	{
		while (cnt)
		{
			cnt = 0;
			tmp2 = flnk;
			tmp = flnk->next;
			while (tmp && tmp->next != NULL)
			{
				if ((tmp->timestamp - tmp->next->timestamp) < 0)
				{
					tmp2->next = ft_list_switch(tmp, tmp->next);
					cnt = 1;
				}
				tmp2 = tmp;
				if (tmp->next != NULL)
					tmp = tmp->next;
			}
		}
	}
	return (lnk);
}

t_list2	*ft_sort_r_time(t_list2 *lnk, t_list2 *t1, t_list2 *t2, t_list2 *flnk)
{
	int		cnt;

	cnt = 1;
	if (lnk != NULL && lnk->next != NULL )
	{
		while (cnt)
		{
			cnt = 0;
			t2 = flnk;
			t1 = flnk->next;
			while (t1->next != NULL)
			{
				if ((t1->timestamp - t1->next->timestamp) > 0)
				{
					t2->next = ft_list_switch(t1, t1->next);
					cnt = 1;
				}
				t2 = t1;
				if (t1->next != NULL)
					t1 = t1->next;
			}
		}
	}
	return (lnk);
}
