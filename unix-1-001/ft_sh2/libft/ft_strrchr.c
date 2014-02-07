/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:24:03 by rgary             #+#    #+#             */
/*   Updated: 2013/11/22 15:23:27 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strrchr(const char *str, int l)
{
	int		i;
	char	c;

	i = 0;
	c = (unsigned char)l;
	while (((char*)str)[i] != '\0')
		i++;
	while (((char*)str)[i] != c)
	{
		if (i < 0)
			return (NULL);
		i--;
	}
	return ((char*)str + i);
}
