/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 12:03:05 by rgary             #+#    #+#             */
/*   Updated: 2014/02/15 13:57:38 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_25_lines(const char *s, float *sign, float *val, int nbr[2])
{
	nbr[1] = *s - '0';
	if (nbr[1] >= 0 && nbr[1] <= 9)
	{
		if (nbr[0] == 1)
			*sign /= 10.0;
		*val = *val * 10.0 + (float)nbr[1];
	};
}

float	ft_atof(const char *s)
{
	float	val;
	float	sign;
	int		nbr[2];

	nbr[0] = 0;
	val = 0;
	sign = 1;
	if (*s == '-')
	{
		s++;
		sign = -1;
	};
	while (*s)
	{
		if (*s == '.')
		{
			nbr[0] = 1;
			s++;
			continue ;
		};
		ft_25_lines(s, &sign, &val, nbr);
		s++;
	};
	return (val * sign);
}
