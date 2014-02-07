/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_build_arg_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 16:24:08 by rgary             #+#    #+#             */
/*   Updated: 2013/12/19 18:00:02 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_arg	*ft_build_arglst_star(t_op *op, va_list *ap, t_arg *lnk)
{
	t_arg	*new;

	new = ft_build_arg_link_int(lnk, ap);
	lnk = ft_arg_list_push_back(lnk, new);
	if (op->conv == 'd' || op->conv == 'c' || op->conv == 'i')
		new = ft_build_arg_link_int(lnk, ap);
	else if (op->conv == 'u' || op->conv == 'o' || op->conv == 'x'
			|| op->conv == 'X' || op->conv == 'p')
		new = ft_build_arg_link_uint(lnk, ap);
	else if (op->conv == 's')
		new = ft_build_arg_link_charstar(lnk, ap);
	else
		new = ft_build_arg_empty(lnk);
	lnk = ft_arg_list_push_back(lnk, new);
	return (lnk);
}

t_arg	*ft_build_no_star(t_op *op, va_list *ap, t_arg *lnk)
{
	t_arg	*new;

	if (op->conv == 'd' || op->conv == 'c' || op->conv == 'i')
		new = ft_build_arg_link_int(lnk, ap);
	else if (op->conv == 'u' || op->conv == 'o' || op->conv == 'x'
			|| op->conv == 'X' || op->conv == 'p')
		new = ft_build_arg_link_uint(lnk, ap);
	else if (op->conv == 's')
		new = ft_build_arg_link_charstar(lnk, ap);
	else
		new = ft_build_arg_empty(lnk);
	lnk = ft_arg_list_push_back(lnk, new);
	return (lnk);
}

t_arg	*ft_build_arglst_conv(t_op *op, va_list *ap, t_arg *lnk, int argcnt)
{
	int		i;
	int		j;
	t_op	*save;

	i = 0;
	j = 0;
	save = op;
	while (i < argcnt)
	{
		if (!op->starwidth)
			lnk = ft_build_no_star(op, ap, lnk);
		if (op->starwidth == '*')
			lnk = ft_build_arglst_star(op, ap, lnk);
		op = op->next;
		i++;
	}
	op = save;
	return (lnk);
}
