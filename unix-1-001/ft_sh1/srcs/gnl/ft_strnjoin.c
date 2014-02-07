/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 12:25:11 by sbuono            #+#    #+#             */
/*   Updated: 2013/12/02 12:29:16 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(const char *str);

char	*ft_strnjoin(const char *s1, const char *s2, int n)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(s1) + n + 1))))
		return (NULL);
	while (s1[++i] != '\0')
		tmp[i] = s1[i];
	while (s2[j] != '\0' && n > 0)
	{
		tmp[i] = s2[j];
		i++;
		j++;
		n--;
	}
	tmp[i] = '\0';
	return (tmp);
}
