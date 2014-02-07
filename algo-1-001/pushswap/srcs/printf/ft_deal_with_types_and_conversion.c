/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_types_and_conversion.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 13:58:29 by rgary             #+#    #+#             */
/*   Updated: 2013/12/19 18:12:35 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_deal_with_octal_conversion(t_op *op, t_arg *lnk)
{
	if (op->flag && ft_strichr(op->flag, '#') != -1 && lnk->ull != 0)
		ft_putchar('0');
	if (ft_strncmp(op->mod, "hh", 2) == 0)
	{
		ft_putchar((UCHAR)lnk->ull);
		lnk->ps += 1;
	}
	else if (ft_strncmp(op->mod, "h", 1) == 0)
	{
		ft_putstr(ft_convert_to_octal((USHORT)lnk->ull));
		lnk->ps += ft_strlen(ft_convert_to_octal((USHORT)lnk->ull));
	}
	else
		ft_deal_with_oct_spe_conv(op, lnk);
	if (op->flag && ft_strichr(op->flag, '#') != -1 && lnk->ull != 0)
		lnk->ps += 1;
}

t_arg	*ft_deal_with_even_even_more(t_op *op, t_arg *lnk)
{
	if (op->conv == 's')
	{
		if (lnk->str)
		{
			ft_putstr(lnk->str);
			lnk->ps = ft_strlen(lnk->str);
		}
		else
		{
			ft_putstr("(null)");
			lnk->ps = 6;
		}
	}
	return (lnk);
}

t_arg	*ft_deal_with_even_more(t_op *op, t_arg *lnk)
{
	if (op->conv == 'c')
	{
		if (ft_strncmp(op->mod, "l", 1) == 0)
		{
			lnk->ps = 1;
			ft_putwchar(lnk->i);
		}
		else
		{
			lnk->ps = 1;
			ft_putchar(lnk->i);
		}
	}
	lnk = ft_deal_with_even_even_more(op, lnk);
	return (lnk);
}

t_arg	*ft_deal_with_more(t_op *op, t_arg *lnk)
{
	if (op->conv == 'u')
	{
		ft_create_padding(op, &lnk);
		ft_deal_with_uint_conversion_part1(op, lnk);
	}
	else if (op->conv == 'o')
	{
		ft_create_padding(op, &lnk);
		ft_deal_with_octal_conversion(op, lnk);
	}
	else if (op->conv == 'x' || op->conv == 'X' || op->conv == 'p')
	{
		ft_deal_with_hexa_conversion(op, lnk);
	}
	lnk = ft_deal_with_even_more(op, lnk);
	return (lnk);
}

t_arg	*ft_deal_with_types_and_conversion(t_op *op, t_arg *lnk)
{
	if (op->conv == 'd' || op->conv == 'i')
	{
		ft_create_padding(op, &lnk);
		if (op->flag && (ft_strichr(op->flag, ' ') != -1) && ((int)lnk->i >= 0)
			&& (ft_strichr(op->flag, '+') == -1))
		{
			lnk->ps += 1;
			ft_putchar(' ');
		}
		else if (op->flag && ((int)lnk->i >= 0)
				&& (ft_strichr(op->flag, '+') != -1))
		{
			lnk->ps += 1;
			ft_putchar('+');
		}
		ft_deal_with_int_conversion_part1(op, lnk);
	}
	lnk = ft_deal_with_more(op, lnk);
	return (lnk);
}
