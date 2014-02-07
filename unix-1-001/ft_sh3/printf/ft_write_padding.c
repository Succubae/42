/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 16:52:43 by rgary             #+#    #+#             */
/*   Updated: 2013/12/19 16:57:45 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		ft_place_zeros(t_op *op, t_arg *lnk, int l)
{
	if (l < op->min_width)
	{
		while (l < op->min_width)
		{
			ft_putchar('0');
			lnk->ps += 1;
			l++;
		}
	}
}

void		ft_place_spaces(t_op *op, t_arg *lnk, int l)
{
	if (l < op->min_width)
	{
		while (l < op->min_width)
		{
			ft_putchar(' ');
			lnk->ps += 1;
			l++;
		}
	}
}
