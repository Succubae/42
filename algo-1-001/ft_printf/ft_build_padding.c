/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 12:09:39 by rgary             #+#    #+#             */
/*   Updated: 2013/12/21 19:45:21 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <stddef.h>
#include <inttypes.h>
#include "ft_printf.h"

char		*ft_itoa_by_type(char *str, t_op *op, t_arg *lnk)
{
	if (ft_strncmp(op->mod, "hh", 2) == 0)
		ft_putchar((signed char)lnk->i);
	else if (ft_strncmp(op->mod, "h", 1) == 0)
		str = ft_itoa((short)lnk->i);
	else if (CMP(op->mod, "ll", 2) == 0 || CMP(op->mod, "l", 1) == 0)
		str = ft_itoa((long)lnk->i);
	else if (ft_strncmp(op->mod, "j", 1) == 0)
		str = ft_itoa((intmax_t)lnk->i);
	else if (ft_strncmp(op->mod, "t", 1) == 0)
		str = ft_itoa((ptrdiff_t)lnk->i);
	else if (ft_strncmp(op->mod, "z", 1) == 0)
		str = ft_itoa((size_t)lnk->i);
	else if (ft_strncmp(op->mod, "q", 1) == 0)
		str = ft_itoa((quad_t)lnk->i);
	else
		str = ft_itoa((int)lnk->i);
	return (str);
}

char		*ft_itoa_by_utype(char *str, t_op *op, t_arg *lnk)
{
	if (ft_strncmp(op->mod, "hh", 2) == 0)
		ft_putchar((unsigned char)lnk->ull);
	else if (ft_strncmp(op->mod, "h", 1) == 0)
		str = ft_uitoa((unsigned short)lnk->ull);
	else if (CMP(op->mod, "ll", 2) == 0 || CMP(op->mod, "l", 1) == 0)
		str = ft_uitoa((unsigned long)lnk->ull);
	else if (ft_strncmp(op->mod, "j", 1) == 0)
		str = ft_uitoa((uintmax_t)lnk->ull);
	else if (ft_strncmp(op->mod, "t", 1) == 0)
		str = ft_uitoa((unsigned int)lnk->ull);
	else if (ft_strncmp(op->mod, "z", 1) == 0)
		str = ft_uitoa((size_t)lnk->ull);
	else if (ft_strncmp(op->mod, "q", 1) == 0)
		str = ft_uitoa((u_quad_t)lnk->ull);
	else
		str = ft_uitoa((unsigned int)lnk->ull);
	return (str);
}

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

void	ft_place_spaces(t_op *op, t_arg *lnk, int l)
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

void		ft_create_padding(t_op *op, t_arg *lnk)
{
	char	*str;
	int		l;
	int		k;

	k = 0;
	str = NULL;
	if (op->conv == 'd' || op->conv == 'i')
		str = ft_itoa_by_type(str, op, lnk);
	else if (op->conv == 'u' || op->conv == 'x' || op->conv == 'X'
			|| op->conv == 'o')
		str = ft_itoa_by_utype(str, op, lnk);
	else
		return ;
	l = ft_strlen(str);
	if (op->min_width && l < op->min_width && op->flag
		&& ft_strichr(op->flag, '0') != -1)
		ft_place_zeros(op, lnk, l);
	else if (op->min_width && l < op->min_width
			&& ft_strichr(op->flag, '0') == -1)
		ft_place_spaces(op, lnk, l);
}
