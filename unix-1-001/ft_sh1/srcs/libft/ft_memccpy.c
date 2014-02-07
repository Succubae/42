/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:04:45 by rgary             #+#    #+#             */
/*   Updated: 2013/11/25 13:05:18 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	ch;
	int				i;
	char			*tmp;
	char			*tmp2;

	i = 0;
	tmp = (char*)s1;
	tmp2 = (char*)s2;
	ch = (unsigned char)c;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		if (tmp2[i] == ch)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
