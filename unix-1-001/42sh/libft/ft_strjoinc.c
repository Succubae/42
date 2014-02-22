/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:40:42 by mfaye             #+#    #+#             */
/*   Updated: 2013/11/29 15:45:07 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoinc(char const *s1, char const c)
{
	char	*join;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	join = ft_strnew(len_s1 + 2);
	if (join == NULL)
		return (NULL);
	join = (char *) ft_memcpy(join, s1, len_s1);
	join[len_s1] = c;
	return (join);
}
