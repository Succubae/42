/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:50:23 by rgary             #+#    #+#             */
/*   Updated: 2013/11/25 11:14:05 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *str, const char *str2, size_t l)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = ft_strlen(str);
	if (l <= k)
		return (l + ft_strlen((char*)str2));
	while (str[i] != '\0' && i < k)
		i++;
	while (str2[j] != '\0' && i < (l - 1))
		str[i++] = str2[j++];
	str[l] = '\0';
	return ((ft_strlen((char*)str2)) + k);
}
