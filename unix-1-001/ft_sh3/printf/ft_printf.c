/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 16:38:28 by rgary             #+#    #+#             */
/*   Updated: 2014/01/29 12:29:45 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

void		free_arg_list(t_arg *lnk)
{
	t_arg	*tmp;

	while (lnk)
	{
		tmp = lnk->next;
		free(lnk);
		lnk = tmp;
	}
}

void		free_op_list(t_op *op)
{
	t_op	*tmp;

	while (op)
	{
		tmp = op->next;
		if (op->flag != NULL)
			free(op->flag);
		if (op->mod != NULL)
			free(op->mod);
		free(op);
		op = tmp;
	}
}

int			ft_printf(const char *format, ...)
{
	int			i;
	int			argcnt;
	t_op		*op;
	va_list		ap;
	t_arg		*lnk;

	op = NULL;
	argcnt = ft_find_arg_count((char*)format);
	va_start(ap, format);
	op = ft_analyse_str((char*)format, op);
	lnk = NULL;
	lnk = ft_build_arglst_conv(op, &ap, lnk, argcnt);
	i = ft_print_out((char*)format, op, lnk);
	va_end(ap);
	free_arg_list(lnk);
	free_op_list(op);
	return (i);
}
