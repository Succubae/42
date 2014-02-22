/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:08:32 by mfaye             #+#    #+#             */
/*   Updated: 2013/11/26 16:18:04 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_ul	count_nbr(t_ul n)
{
	t_ul	count;

	count = 1;
	while (n / 10 > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	set_mod_and_div(t_ul *mod, t_ul *div, t_ul base, t_ul n)
{
	*mod = n % base;
	*div = n / base;
}

static char	*make_string(char *toa, t_ul n, t_ul base)
{
	char	c_val;
	t_ul	mod;
	t_ul	div;

	if (n >= base)
	{
		set_mod_and_div(&mod, &div, base, n);
		if (div != 0)
			toa = make_string(toa, div, base);
		make_string(toa, mod, base);
	}
	else
	{
		if (base <= 10)
			c_val = (char) n + '0';
		else
		{
			if (n <= 9)
				c_val = (char) n + '0';
			else
				c_val = (char) (n - 10) + 'a';
		}
		*toa = c_val;
	}
	return (toa + 1);
}

char		*ft_utoa(t_ul n, t_ul base)
{
	t_ul	nb_nbr;
	char	*toa;

	nb_nbr = count_nbr(n);
	toa = ft_strnew(nb_nbr + 1);
	make_string(toa, n, base);
	return (toa);
}
