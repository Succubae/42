/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_big_endian.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:18:09 by rgary             #+#    #+#             */
/*   Updated: 2014/01/17 15:33:18 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "asm.h"

int		swa_swap_char_by_params(char *s, int size, int type)
{
	int		i;
	int		swap;

	if (type == 0)
		i = ft_atoi(s + 1);
	else
		i = ft_atoi(s);
	while (i < 0 && size == 2)
		i = 65536 + i;
	if (i < 0 && size == 4)
		i = 4294967296 + i;
	if (size == 2)
		swap = (i >> 8) | (i << 8);
	else if (size == 4)
	{
		swap = ((i >> 24) & 0xff)
			| ((i << 8) & 0xff0000)
			| ((i >> 8) & 0xff00)
			| ((i << 24) & 0xff000000);
	}
	return (swap);
}

int		swa_swap_int_by_params(int i, int size)
{
	int		swap;

	if (size == 2)
		swap = (i >> 8) | (i << 8);
	if (size == 4)
	{
		swap = ((i >> 24) & 0xff)
			| ((i << 8) & 0xff0000)
			| ((i >> 8) & 0xff00)
			| ((i << 24) & 0xff000000);
	}
	return (swap);
}
