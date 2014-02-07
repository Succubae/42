/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_arg_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 10:45:46 by rgary             #+#    #+#             */
/*   Updated: 2013/12/21 19:01:02 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
t_arg	*ft_build_arg_link_int(t_arg *lnk, va_list *ap)
{
	lnk = (t_arg*)malloc(sizeof(t_arg));
	lnk->i = va_arg(*ap, long);
	lnk->ps = 0;
	lnk->ull = 0;
	lnk->str = NULL;
	lnk->next = NULL;
	return (lnk);
}

t_arg	*ft_build_arg_link_uint(t_arg *lnk, va_list *ap)
{
	lnk = (t_arg*)malloc(sizeof(t_arg));
	lnk->ull = va_arg(*ap, unsigned long);
	lnk->ps = 0;
	lnk->i = 0;
	lnk->str = NULL;
	lnk->next = NULL;
	return (lnk);
}

t_arg	*ft_build_arg_link_charstar(t_arg *lnk, va_list *ap)
{
	lnk = (t_arg*)malloc(sizeof(t_arg));
	lnk->str = va_arg(*ap, char*);
	lnk->ps = 0;
	lnk->i = 0;
	lnk->ull = 0;
	lnk->next = NULL;
	return (lnk);
}

t_arg	*ft_build_arg_empty(t_arg *lnk)
{
	lnk = (t_arg*)malloc(sizeof(t_arg));
	lnk->str = NULL;
	lnk->ps = 0;
	lnk->i = 0;
	lnk->ull = 0;
	lnk->next = NULL;
	return (lnk);
}

t_arg	*ft_build_arglst_conv(t_op *op, va_list *ap, t_arg *lnk, int argcnt)
{
	int		i;
	t_arg	*new;
	int		j;
	t_op	*save;

	i = 0;
	j = 0;
	save = op;
	while (i < argcnt)
	{
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
		op = op->next;
		i++;
	}
	op = save;
	return (lnk);
}
