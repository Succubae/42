/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 10:40:07 by rgary             #+#    #+#             */
/*   Updated: 2013/12/21 18:45:17 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int			ft_find_arg_count(char *str)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '%')
			cnt += 1;
		i++;
	}
	return (cnt);
}

int		ft_print_out_3(int *i, t_op *op, t_arg *lnk)
{
	int		cnt;

	cnt = 0;
	*i += 1;
	ft_deal_with_types_and_conversion(op, lnk);
	if (op->conv)
	{
		*i += op->arg_size;
		cnt += lnk->ps;
	}
	op = op->next;
	lnk = lnk->next;
	return (cnt);
}

int		ft_print_out_2(int *i, t_op *op, char *str, t_arg *lnk)
{
	int		cnt;

	cnt = 0;
	if (str[*i] == '%')
	{
		if (str[*i + 1] == '%' || str[*i + 1] == 'Z'
			|| str[*i + op->arg_size + 1] == '%')
		{
			if (str[*i + 1] == '%')
				ft_putchar('%');
			else if (str[*i + 1] == 'Z')
				ft_putchar('Z');
			else if (str[*i + op->arg_size + 1] == '%')
			{
				ft_putchar('%');
				*i += op->arg_size - 1;
			}
			*i += 2;
			cnt += 1;
		}
		else
			cnt += ft_print_out_3(i, op, lnk);
	}
	return (cnt);
}

int			ft_print_out(char *str, int i, t_op *op, t_arg *lnk)
{
	int		cnt;

	cnt = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			ft_putchar(str[i]);
			cnt += 1;
			i++;
		}
		cnt += ft_print_out_2(&i, op, str, lnk);
	}
	return (cnt);
}
