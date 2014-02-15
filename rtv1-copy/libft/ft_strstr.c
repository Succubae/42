/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:53:31 by rgary             #+#    #+#             */
/*   Updated: 2013/11/22 15:23:57 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strstr(const char *str, const char *str2)
{
	int		i;

	i = 0;
	if (*str2 == '\0')
		return ((char*)str);
	while (*str != '\0' && *str != *str2)
		str++;
	if (*str == '\0')
		return (NULL);
	while (*str != '\0')
	{
		if (ft_strncmp((char*)str, (char*)str2, ft_strlen(str2)) == 0)
			return ((char*)str);
		str++;
	}
	return (NULL);
}
