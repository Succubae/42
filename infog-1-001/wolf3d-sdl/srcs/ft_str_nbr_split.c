/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_nbr_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:44:44 by rgary             #+#    #+#             */
/*   Updated: 2013/12/20 10:16:01 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "wolf3d.h"

static int		ft_findNumderSplit(const char *s)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (*s != '\0')
	{
		while (*s < '0' || *s > '9')
			s++;
		if (s[i] != '\0')
		{
			n++;
			while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
				i++;
			s = (s + i);
			i = 0;
		}
	}
	return (n);
}

static int		ft_findLen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
		i++;
	return (i + 1);
}

static int		*ft_tabInt(const char *s, int nbstr)
{
	int		*tab;
	int		i;

	i = 0;
	tab = (int*)malloc(sizeof(int) * nbstr);
	while (*s != '\0')
	{
		while (*s < '0' || *s > '9')
			s++;
		if (*s != '\0')
		{
			tab[i++] = ft_findLen(s);
			while ((*s >= '0' && *s <= '9') && *s != '\0')
				s++;
		}
	}
	return (tab);
}

static char		**ft_mallocTab(const char *s)
{
	int		*tab;
	char	**table;
	int		nbstr;

	nbstr = ft_findNumderSplit(s);
	tab = ft_tabInt(s, nbstr);
	if (!(table = (char**)malloc(sizeof(char*) * (nbstr + 1))))
		return (NULL);
	while (--nbstr > -1)
	{
		if (!(table[nbstr] = (char*)malloc(sizeof(char) * tab[nbstr])))
			return (NULL);
	}
	return (table);
}

char			**ft_str_nbr_split(const char *s)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	if (!s || !(tab = ft_mallocTab(s)))
		return (NULL);
	while (*s != '\0')
	{
		j = 0;
		while (*s < '0' || *s > '9')
			s++;
		if (*s != '\0')
		{
			while ((*s >= '0' && *s <= '9') && *s != '\0')
			{
				tab[i][j] = *s;
				j++;
				s += 1;
			}
			tab[i++][j] = '\0';
		}
	}
	tab[i] = NULL;
	return (tab);
}
