/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:51:29 by rgary             #+#    #+#             */
/*   Updated: 2013/11/25 11:32:40 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = 0;
	while (start > 0)
	{
		start--;
		i++;
	}
	s2 = (char*)malloc(sizeof(char) * len + 1);
	if (!s2)
		return (NULL);
	while (len > 0 && s[i] != '\0')
	{
		s2[j] = s[i];
		len--;
		j++;
		i++;
	}
	s2[j] = '\0';
	return (s2);
}
