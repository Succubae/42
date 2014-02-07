/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:09:27 by mfaye             #+#    #+#             */
/*   Updated: 2013/11/22 14:59:13 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	ft_bzero(void *, size_t);

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char *) malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
