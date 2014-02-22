/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:00:45 by mfaye             #+#    #+#             */
/*   Updated: 2013/11/21 11:41:41 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	val;
	size_t			i;
	char			*dest;

	dest = (char *) b;
	val = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		dest[i] = val;
		i++;
	}
	return (b);
}
