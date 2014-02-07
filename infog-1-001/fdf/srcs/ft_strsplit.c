/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:44:44 by rgary             #+#    #+#             */
/*   Updated: 2013/12/20 10:17:45 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "fdf.h"

static int		ft_findNumderSplit(const char *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (s[i] != '\0')
		{
			n++;
			while (s[i] != c && s[i] != '\0')
				i++;
			s = (s + i);
			i = 0;
		}
	}
	return (n);
}

static int		ft_findLen(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i + 1);
}

static int		*ft_tabInt(const char *s, char c)
{
	int		*tab;
	int	 i;

	i = 0;
	tab = (int*)malloc(sizeof(int) * ft_findNumderSplit(s, c));
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			tab[i++] = ft_findLen(s, c);
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (tab);
}

static	char	**ft_mallocTab(const char *s, char c)
{
	int		*tab;
	char	**table;
	int		nbstr;

	nbstr = ft_findNumderSplit(s, c);
	tab = ft_tabInt(s, c);
	if (!(table = (char**)malloc(sizeof(char*) * (nbstr + 1))))
		return (NULL);
	while (--nbstr > -1)
	{
		if (!(table[nbstr] = (char*)malloc(sizeof(char) * tab[nbstr])))
			return (NULL);
	}
	return (table);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	if (!s || !(tab = ft_mallocTab(s, c)))
		return (NULL);
	while (*s != '\0')
	{
		j = 0;
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			while (*s != c && *s != '\0')
			{
				tab[i][j] = *s;
				j++;
				s++;
			}
			tab[i++][j] = '\0';
		}
	}
	tab[i] = NULL;
	return (tab);
}
