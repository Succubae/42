/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_length_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:13:38 by rgary             #+#    #+#             */
/*   Updated: 2013/12/23 19:33:10 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

int		ft_count_length(const char *s, char c, int *i)
{
	int		j;

	j = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		*i += 1;
		j++;
	}
	return (j);
}

int		*ft_build_length_tab(const char *s, char c, int wdcnt)
{
	int		i;
	int		j;
	int		l;
	int		*tab;

	i = j = l = 0;
	if (!(tab = (int*)malloc(sizeof(int) * wdcnt)))
		return (NULL);
	while (s[j] != '\0' && i < wdcnt)
	{
		while (s[j] == c)
			j++;
		if (s[j] != c)
			l = ft_count_length(s, c, &j);
		tab[i] = l + 1;
		l = 0;
		j++;
		i++;
	}
	return (tab);
}
