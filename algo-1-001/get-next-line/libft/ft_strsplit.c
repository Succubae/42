/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:44:44 by rgary             #+#    #+#             */
/*   Updated: 2013/11/26 16:30:32 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static char		**ft_build_tab_tab(const char *s, char c)
{
	int		wdcnt;
	int		*nb;
	char	**tab;

	wdcnt = ft_word_count(s, c);
	nb = ft_build_length_tab(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (wdcnt + 1))))
		return (NULL);
	while (wdcnt > -1)
	{
		if (!(tab[wdcnt] = (char*)malloc(sizeof(char) * nb[wdcnt])))
			return (NULL);
		wdcnt -= 1;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	if (!(tab = ft_build_tab_tab(s, c)))
		return (NULL);
	while (*s != '\0')
	{
		j = 0;
		while (*s == c)
			s = s + 1;
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
