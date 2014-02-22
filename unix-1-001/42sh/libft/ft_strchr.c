/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:19:49 by mfaye             #+#    #+#             */
/*   Updated: 2013/11/22 15:26:25 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		find;
	size_t		i;
	size_t		size;

	i = 0;
	size = ft_strlen(s);
	find = (char) c;
	while (*s && (find != *s))
	{
		s++;
		i++;
	}
	if ((i == size) && (*s != find))
		return (NULL);
	return ((char *) s);
}
