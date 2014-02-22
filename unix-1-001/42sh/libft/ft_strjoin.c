/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:15:21 by mfaye             #+#    #+#             */
/*   Updated: 2013/11/26 16:13:16 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = ft_strnew(len_s1 + len_s2 + 1);
	if (join == NULL)
		return (NULL);
	join = (char *) ft_memcpy(join, s1, len_s1);
	ft_memcpy(join + len_s1, s2, len_s2);
	return (join);
}
