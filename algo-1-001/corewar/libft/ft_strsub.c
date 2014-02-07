/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:23:55 by mfaye             #+#    #+#             */
/*   Updated: 2013/11/26 16:12:28 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, t_ui start, size_t len)
{
	char	*sub;
	t_ui	i;

	i = 0;
	sub = ft_strnew(len + 1);
	if (sub == NULL)
		return (NULL);
	s += start;
	while (s[i] && len != 0)
	{
		sub[i] = s[i];
		i++;
		len--;
	}
	return (sub);
}
