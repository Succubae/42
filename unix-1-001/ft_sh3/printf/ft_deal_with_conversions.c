/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_conversions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:13:30 by rgary             #+#    #+#             */
/*   Updated: 2013/12/26 10:50:24 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_deal_with_int_conversion_part1(t_op *op, t_arg *lnk)
{
	if (op->mod)
	{
		if (ft_strncmp(op->mod, "hh", 2) == 0)
		{
			ft_putchar((signed char)lnk->i);
			lnk->ps += 1;
		}
		else if (ft_strncmp(op->mod, "h", 1) == 0)
		{
			ft_putnbr((short)lnk->i);
			lnk->ps += ft_strlen(ft_itoa((short)lnk->i));
		}
		else if (ft_strncmp(op->mod, "ll", 2) == 0
				|| ft_strncmp(op->mod, "l", 1) == 0
				|| ft_strncmp(op->mod, "q", 1) == 0)
		{
			ft_putnbr((long)lnk->i);
			lnk->ps += ft_strlen(ft_itoa((long)lnk->i));
		}
	}
	else
	{
		ft_putnbr((int)lnk->i);
		lnk->ps += ft_strlen(ft_itoa((int)lnk->i));
	}
}

void	ft_deal_with_uint_conversion_part1(t_op *op, t_arg *lnk)
{
	if (op->mod)
	{
		if (ft_strncmp(op->mod, "hh", 2) == 0)
		{
			ft_putchar((unsigned char)lnk->ull);
			lnk->ps += 1;
		}
		else if (ft_strncmp(op->mod, "h", 1) == 0)
		{
			ft_putunbr((unsigned short)lnk->ull);
			lnk->ps += ft_strlen((char*)ft_uitoa((unsigned short)lnk->ull));
		}
		else if (ft_strncmp(op->mod, "ll", 2) == 0
				|| ft_strncmp(op->mod, "l", 1) == 0
				|| ft_strncmp(op->mod, "q", 1) == 0)
		{
			ft_putunbr((unsigned long)lnk->ull);
			lnk->ps += ft_strlen((char*)ft_uitoa((unsigned long)lnk->ull));
		}
	}
	else
	{
		ft_putunbr((unsigned int)lnk->ull);
		lnk->ps += ft_strlen((char*)ft_uitoa((unsigned int)lnk->ull));
	}
}

void	ft_deal_with_hex_spe_conv(t_op *op, t_arg *lnk)
{
	if (op->mod)
	{
		if (ft_strncmp(op->mod, "hh", 2) == 0)
		{
			ft_putchar((UCHAR)lnk->ull);
			lnk->ps += 1;
		}
		else if (ft_strncmp(op->mod, "h", 1) == 0)
		{
			ft_putstr(ft_convert_to_hexa((USHORT)lnk->ull, op->conv));
			lnk->ps += ft_strlen(FCTH((USHORT)lnk->ull, op->conv));
		}
		else if (ft_strncmp(op->mod, "ll", 2) == 0
				|| ft_strncmp(op->mod, "l", 1) == 0
				|| ft_strncmp(op->mod, "q", 1) == 0 || op->conv == 'p')
		{
			ft_putstr(ft_convert_to_hexa((ULONG)lnk->ull, op->conv));
			lnk->ps += ft_strlen(FCTH((ULONG)lnk->ull, op->conv));
		}
	}
	else
	{
		ft_putstr(ft_convert_to_hexa((UINT)lnk->ull, op->conv));
		lnk->ps += ft_strlen(ft_convert_to_hexa((UINT)lnk->ull, op->conv));
	}
}

void	ft_deal_with_hexa_conversion(t_op *op, t_arg *lnk)
{
	if ((op->flag && ft_strichr(op->flag, '#') != -1 && lnk->ull != 0
		&& ft_strichr(op->flag, '0') == -1) || op->conv == 'p')
	{
		ft_create_padding(op, &lnk);
		ft_putstr("0x");
	}
	else if ((op->flag && ft_strichr(op->flag, '#') != -1 && lnk->ull != 0
			&& ft_strichr(op->flag, '0') != -1) || op->conv == 'p')
	{
		ft_putstr("0x");
		ft_create_padding(op, &lnk);
	}
	else if (lnk->ull == 0)
		ft_create_padding(op, &lnk);
	ft_deal_with_hex_spe_conv(op, lnk);
	if ((op->flag && ft_strichr(op->flag, '#') != -1 && lnk->ull != 0)
		|| op->conv == 'p')
		lnk->ps += 2;
}

void	ft_deal_with_oct_spe_conv(t_op *op, t_arg *lnk)
{
	if (ft_strncmp(op->mod, "ll", 2) == 0
		|| ft_strncmp(op->mod, "l", 1) == 0
		|| ft_strncmp(op->mod, "q", 1) == 0)
	{
		ft_putstr(ft_convert_to_octal((ULONG)lnk->ull));
		lnk->ps += ft_strlen(ft_convert_to_octal((ULONG)lnk->ull));
	}
	else
	{
		ft_putstr(ft_convert_to_octal((UINT)lnk->ull));
		lnk->ps += ft_strlen(ft_convert_to_octal((UINT)lnk->ull));
	}
}
