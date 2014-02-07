/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:45:08 by rgary             #+#    #+#             */
/*   Updated: 2013/11/25 13:05:58 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	char			*tmp;
	int				i;

	i = 0;
	ch = (unsigned char)c;
	tmp = (char*)s;
	while (tmp[i] != ch && n > 0)
	{
		i++;
		n--;
	}
	if (tmp[i] == ch)
	{
		while (i > 0)
		{
			s++;
			i--;
		}
		return ((char*)s);
	}
	else
		return (NULL);
}
