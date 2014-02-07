/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:58:52 by rgary             #+#    #+#             */
/*   Updated: 2013/12/08 09:43:09 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "fdf.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	int		l;
	int		i;
	int		j;
	char	*s3;

	i = 0;
	l = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	s3 = (char*)malloc(sizeof(char) * l);
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0' && j < n)
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}
