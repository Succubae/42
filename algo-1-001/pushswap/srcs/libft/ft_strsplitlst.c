/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:19:38 by rgary             #+#    #+#             */
/*   Updated: 2013/12/20 11:30:09 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

t_list			*ft_lpb(t_list *lnk, t_list *new)
{
	t_list		*save;

	save = lnk;
	if (lnk == NULL)
		return (new);
	while (lnk->next != NULL)
	{
		lnk = lnk->next;
	}
	lnk->next = new;
	return (save);
}

static int		ft_word_count_lst(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			j++;
			i++;
			while (s[i] == c)
				i++;
		}
		i++;
	}
	return (j);
}

static int		*ft_build_length_tab_lst(const char *s, char c)
{
	int		i;
	int		j;
	int		l;
	int		*tab;

	i = 0;
	j = 0;
	l = 0;
	if (!(tab = (int*)malloc(sizeof(int) * (ft_word_count_lst(s, c)))))
		return (NULL);
	while (s[j] != '\0' && i < (ft_word_count_lst(s, c)))
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		while (s[j] != c && s[j] != '\0')
		{
			l++;
			j++;
		}
		tab[i] = l;
		l = 0;
		j++;
		i++;
	}
	return (tab);
}

t_list			*ft_strsplitlst(const char *s, char c)
{
	int		i;
	int		j;
	int		*t;
	t_list	*lnk;

	i = 0;
	j = 0;
	t = ft_build_length_tab_lst(s, c);
	lnk = NULL;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c)
		{
			lnk = ft_lpb(lnk, ft_lstnew(ft_strsub(s, i, t[j]), t[j]));
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		j++;
	}
	return (lnk);
}
