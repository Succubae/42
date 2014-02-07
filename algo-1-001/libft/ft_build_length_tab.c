/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_length_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:13:38 by rgary             #+#    #+#             */
/*   Updated: 2013/11/27 11:28:39 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

#include <stdio.h>
int		*ft_build_length_tab(const char *s, char c)
{
	int		i;
	int		j;
	int		l;
	int		*tab;

	i = 0;
	j = 0;
	l = 0;
	if (!(tab = (int*)malloc(sizeof(int) * ft_word_count(s, c))))
		return (NULL);
	while (s[j] != '\0' && i < ft_word_count(s, c))
	{
		while (s[j] == c)
			j++;
		if (s[j] != c)
		{
			while (s[j++] != c && s[j] != '\0')
				l++;
		}
		tab[i] = l + 1;
		l = 0;
		j++;
		i++;
	}
	return (tab);
}
