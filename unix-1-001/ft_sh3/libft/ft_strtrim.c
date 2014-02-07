/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:33:39 by rgary             #+#    #+#             */
/*   Updated: 2013/11/26 16:38:16 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		l;
	int		k;
	char	*s2;

	i = 0;
	l = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
		i++;
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (!(s2 = (char*)malloc(sizeof(char) * (j - i))))
		return (NULL);
	k = i;
	while (((j + 1) - k) > 0)
	{
		s2[l] = s[i++];
		j--;
		l++;
	}
	s2[l] = '\0';
	return (s2);
}
