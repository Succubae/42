/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 12:09:39 by rgary             #+#    #+#             */
/*   Updated: 2013/12/26 10:49:34 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <stddef.h>
#include <inttypes.h>
#include "ft_printf.h"

char		*ft_itoa_by_type(char *str, t_op *op, t_arg *lnk)
{
	if (op->mod)
	{
		if (ft_strncmp(op->mod, "hh", 2) == 0)
			ft_putchar((signed char)lnk->i);
		else if (ft_strncmp(op->mod, "h", 1) == 0)
			str = ft_itoa((short)lnk->i);
		else if (ft_strncmp(op->mod, "ll", 2) == 0
				|| ft_strncmp(op->mod, "l", 1) == 0)
			str = ft_itoa((long)lnk->i);
		else if (ft_strncmp(op->mod, "j", 1) == 0)
			str = ft_itoa((intmax_t)lnk->i);
		else if (ft_strncmp(op->mod, "t", 1) == 0)
			str = ft_itoa((ptrdiff_t)lnk->i);
		else if (ft_strncmp(op->mod, "z", 1) == 0)
			str = ft_itoa((size_t)lnk->i);
		else if (ft_strncmp(op->mod, "q", 1) == 0)
			str = ft_itoa((quad_t)lnk->i);
	}
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
	else if (ft_strncmp(op->mod, "ll", 2) == 0
			|| ft_strncmp(op->mod, "l", 1) == 0)
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

void		ft_pad_by_star(t_op *op, t_arg **lnk)
{
	int		k;
	int		l;
	int		o;
	char	*str;

	k = o = l = 0;
	str = NULL;
	if (op->conv == 'd' || op->conv == 'i')
		l = ft_strlen(ft_itoa_by_type(str, op, (*lnk)->next));
	else if (op->conv == 'u')
		l = ft_strlen(ft_itoa_by_utype(str, op, (*lnk)->next));
	else if (op->conv == 'o')
		l = ft_strlen(ft_convert_to_octal((UINT)(*lnk)->next->ull));
	else if (op->conv == 'x' || op->conv == 'X')
		l = ft_strlen(ft_convert_to_hexa((UINT)(*lnk)->next->ull, op->conv));
	k = (((int)(*lnk)->i != 0) ? (int)(*lnk)->i : (int)(*lnk)->ull);
	while (l < k)
	{
		ft_putchar((ft_strichr(op->flag, '0') != -1 ? '0' : ' '));
		o += 1;
		l++;
	}
	if ((*lnk)->next)
		*lnk = (*lnk)->next;
	(*lnk)->ps = o;
}

void		ft_create_pad_part2(t_op *op, t_arg **lnk, int l)
{
	if (op->flag)
	{
		if (ft_strichr(op->flag, '#') != -1 && ft_strichr(op->flag, '0' != -1)
			&& (*lnk)->ull != 0)
			l += 2;
		if (op->min_width && l < op->min_width && op->flag
			&& ft_strichr(op->flag, '0') != -1 && !op->starwidth)
			ft_place_zeros(op, *lnk, l);
		else if (op->min_width && l < op->min_width
				&& ft_strichr(op->flag, '0') == -1 && !op->starwidth)
			ft_place_spaces(op, *lnk, l);
		else if (op->starwidth == '*')
			ft_pad_by_star(op, lnk);
	}
}

void		ft_create_padding(t_op *op, t_arg **lnk)
{
	char	*str;
	int		l;
	int		k;

	k = 0;
	str = NULL;
	if (op->conv == 'd' || op->conv == 'i')
		str = ft_itoa_by_type(str, op, *lnk);
	else if (op->conv == 'u')
		str = ft_itoa_by_utype(str, op, *lnk);
	else if (op->conv == 'o')
		str = ft_convert_to_octal((UINT)(*lnk)->ull);
	else if (op->conv == 'x' || op->conv == 'X')
		str = ft_convert_to_hexa((UINT)(*lnk)->ull, op->conv);
	else
		return ;
	l = ft_strlen(str);
	ft_create_pad_part2(op, lnk, l);
}
