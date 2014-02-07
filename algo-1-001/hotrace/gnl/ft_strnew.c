/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:11:07 by sbuono            #+#    #+#             */
/*   Updated: 2013/12/02 18:14:25 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	ft_bzero(void *s, size_t n);

char	*ft_strnew(size_t size)
{
	char	*b;

	if ((b = (char*)malloc(sizeof(char) * (size + 1))))
	{
		ft_bzero(b, size + 1);
		return (b);
	}
	return (NULL);
}
