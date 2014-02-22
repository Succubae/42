/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:13:49 by mfaye             #+#    #+#             */
/*   Updated: 2013/11/22 15:28:55 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;
	size_t	i;
	char	find;

	size = ft_strlen(s);
	find = (char) c;
	i = size;
	s += size;
	while ((i > 0) && (find != *s))
	{
		s--;
		i--;
	}
	if ((i == 0) && (*s != find))
		return (NULL);
	return ((char *) s);
}
