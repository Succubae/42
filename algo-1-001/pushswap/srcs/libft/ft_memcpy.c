/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:49:06 by rgary             #+#    #+#             */
/*   Updated: 2013/11/25 12:46:47 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memcpy(void *str, const void *str2, size_t n)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = (char*)str;
	tmp2 = (char*)str2;
	i = 0;
	while (n > 0)
	{
		tmp[i] = tmp2[i];
		i++;
		n--;
	}
	return (str);
}
