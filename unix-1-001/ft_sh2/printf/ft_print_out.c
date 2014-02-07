/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 10:40:07 by rgary             #+#    #+#             */
/*   Updated: 2013/12/19 17:53:42 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_find_arg_count(char *str)
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

void	ft_print_arg_2(int *i, t_op **op, int *cnt, t_arg **lnk)
{
	*i += 1;
	*lnk = ft_deal_with_types_and_conversion(*op, *lnk);
	if ((*op)->conv)
	{
		*i += (*op)->arg_size;
		*cnt += (*lnk)->ps;
	}
	*op = (*op)->next;
	*lnk = (*lnk)->next;
}

void	ft_print_arg_1(char *str, int *i, t_op *op, int *cnt)
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
	*cnt += 1;
}

void	ft_print_char(char *str, int *cnt, int *i)
{
	while (str[*i] != '%' && str[*i] != '\0')
	{
		ft_putchar(str[*i]);
		*cnt += 1;
		*i += 1;
	}
}

int		ft_print_out(char *str, t_op *op, t_arg *lnk)
{
	int		i;
	int		cnt;
	int		j;

	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		ft_print_char(str, &cnt, &i);
		if (str[i] == '%')
		{
			j = op->arg_size;
			if ((str[i + 1] == '%' || str[i + 1] == 'Z'
				|| str[i + op->arg_size + 1] == '%') && IS_N_CONVER)
				ft_print_arg_1(str, &i, op, &cnt);
			else
				ft_print_arg_2(&i, &op, &cnt, &lnk);
		}
	}
	return (cnt);
}
