/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:44:44 by rgary             #+#    #+#             */
/*   Updated: 2014/02/06 13:22:46 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static char		**ft_build_tab_tab(const char *s, char c)
{
	int		wdcnt;
	int		*nb;
	char	**tab;

	if ((wdcnt = ft_word_count(s, c)) < 0)
		wdcnt = 0;
	nb = ft_build_length_tab(s, c, wdcnt);
	if (!(tab = (char**)malloc(sizeof(char*) * (wdcnt + 1))))
		return (NULL);
	wdcnt = wdcnt - 1;
	while (wdcnt > -1)
	{
		if (nb[wdcnt] < 0)
			nb[wdcnt] = 0;
		if (!(tab[wdcnt] = (char*)malloc(sizeof(char) * (nb[wdcnt] + 1))))
			return (NULL);
		wdcnt -= 1;
	}
	free(nb);
	return (tab);
}

char			**ft_fill_word(char **tab, int *i, int *l, const char *s)
{
	int		j;

	j = 0;
	tab[*i][j] = s[*l];
	*l += 1;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		l;
	char	**tab;

	i = l = 0;
	if (!(tab = ft_build_tab_tab(s, c)))
		return (NULL);
	while (s[l] != '\0')
	{
		j = 0;
		while (s[l] == c)
			l++;
		if (s[l] != '\0')
		{
			while (s[l] != c && s[l] != '\0')
			{
				tab[i][j++] = s[l++];
			}
			tab[i][j] = '\0';
			i += 1;
		}
	}
	tab[i] = NULL;
	return (tab);
}
