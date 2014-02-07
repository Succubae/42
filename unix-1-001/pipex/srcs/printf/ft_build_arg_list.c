/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_arg_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 10:45:46 by rgary             #+#    #+#             */
/*   Updated: 2013/12/19 17:23:46 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

t_arg	*ft_arg_list_push_back(t_arg *lnk, t_arg *new)
{
	t_arg	*save;

	save = lnk;
	if (lnk == NULL)
		return (new);
	while (lnk->next)
		lnk = lnk->next;
	lnk->next = new;
	return (save);
}

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
