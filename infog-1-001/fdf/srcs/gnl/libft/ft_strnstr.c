/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:21:58 by rgary             #+#    #+#             */
/*   Updated: 2013/11/22 17:53:10 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;

	if (s2[0] == '\0')
		return ((char*)s1);
	while (*s1 != '\0' && n > 0)
	{
		i = 0;
		if (s1[i] == s2[i])
		{
			while (s1[i] == s2[i] && s1[i] != '\0' && i < n)
				i++;
			if (s2[i] == '\0')
				return ((char*)s1);
		}
		s1++;
		n--;
	}
	return (NULL);
}
