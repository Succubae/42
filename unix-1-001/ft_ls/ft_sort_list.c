/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:11:21 by rgary             #+#    #+#             */
/*   Updated: 2013/12/09 11:01:55 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_ls.h"

int			ft_list_elem_cmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
			i++;
		return (s1[i] - s2[i]);
	}
	return (0);
}

t_list2		*ft_sort_list_elem(t_list2 *lnk, int i)
{
	t_list2		*tmp;
	t_list2		*tmp2;
	t_list2		*flnk;

	if ((flnk = (t_list2*)malloc(sizeof(t_list2))) == NULL)
	{
		ft_putendl_fd("Memory Allocation error.\n", 2);
		exit (1);
	}
	flnk->next = lnk;
	tmp = NULL;
	tmp2 = NULL;
	if (i == 0)
		lnk = ft_sort_name(lnk, tmp, tmp2, flnk);
	else if (i == 1)
		lnk = ft_sort_time(lnk, tmp, tmp2, flnk);
	else if (i == 2)
		lnk = ft_sort_r_name(lnk, tmp, tmp2, flnk);
	else if (i == 3)
		lnk = ft_sort_r_time(lnk, tmp, tmp2, flnk);
	lnk = flnk->next;
	free(flnk);
	return (lnk);
}

t_list2		*ft_sort_name(t_list2 *lnk, t_list2 *tmp, t_list2 *tmp2, t_list2 *flnk)
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
			while (tmp->next != NULL)
			{
				if (ft_list_elem_cmp(tmp->name, tmp->next->name) > 0)
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

t_list2		*ft_list_switch(t_list2 *l1, t_list2 *l2)
{
	l1->next = l2->next;
	l2->next = l1;
	return (l2);
}

t_list2		*ft_sort_r_name(t_list2 *lnk, t_list2 *t1, t_list2 *t2, t_list2 *flnk)
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
				if (ft_list_elem_cmp(t1->name, t1->next->name) < 0)
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
