/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:08:32 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/02 13:18:42 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_nbr(long n)
{
	unsigned int	count;
	unsigned int	i;

	count = 1;
	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		count++;
	}
	if (i > 0)
		return (count + 1);
	return (count);
}

static char			*get_mod_and_div(long *mod, long *div, char *toa, long n)
{
	if (n < 0)
	{
		*mod = (n % 10) * -1;
		*div = (n / 10) * -1;
		*toa = '-';
		toa++;
	}
	else
	{
		*mod = n % 10;
		*div = n / 10;
	}
	return (toa);
}

static char			*make_string(char *toa, long n)
{
	char	c_val;
	long	mod;
	long	div;

	if (n >= 10 || n < 0)
	{
		toa = get_mod_and_div(&mod, &div, toa, n);
		if (div != 0)
			toa = make_string(toa, div);
		make_string(toa, mod);
	}
	else
	{
		c_val = (char) n + 48;
		*toa = c_val;
	}
	return (toa + 1);
}

char				*ft_stoa(long n)
{
	unsigned int	nb_nbr;
	char			*toa;

	nb_nbr = count_nbr(n);
	toa = ft_strnew(nb_nbr + 1);
	make_string(toa, n);
	return (toa);
}
