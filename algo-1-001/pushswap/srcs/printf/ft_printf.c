/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 16:38:28 by rgary             #+#    #+#             */
/*   Updated: 2013/12/19 17:31:17 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

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
	return (i);
}
