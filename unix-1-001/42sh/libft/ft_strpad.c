/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 10:40:51 by mfaye             #+#    #+#             */
/*   Updated: 2013/11/27 10:52:42 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strpad(const char *s, size_t size, t_paddir direction, char pad)
{
	size_t	pad_size;
	char	*pad_str;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (size > s_len)
	{
		pad_size = size - s_len;
		pad_str = ft_strnew(pad_size);
		if ((pad_str = (char *) ft_memset(pad_str, pad, pad_size)) == NULL)
			impossible_malloc("padding");
		if (direction == PAD_LEFT)
			return (ft_strjoin(pad_str, s));
		return (ft_strjoin(s, pad_str));
	}
	return ((char *) s);
}

void	ft_strpad2(char **s, size_t size, t_paddir direction, char pad)
{
	char	*tmp;

	tmp = ft_strpad(*s, size, direction, pad);
	if (tmp != *s)
	{
		free(*s);
		*s = ft_strdup(tmp);
		free(tmp);
	}
}