/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:39:01 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/31 15:01:42 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	int		i;

	str1 = (char *) s1;
	str2 = (char *) s2;
	i = 0;
	while (n != 0)
	{
		str1[i] = str2[i];
		n--;
		i++;
	}
	return (str1);
}
