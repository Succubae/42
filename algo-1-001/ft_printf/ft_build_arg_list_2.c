/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_arg_list_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 18:16:28 by rgary             #+#    #+#             */
/*   Updated: 2013/12/21 18:50:40 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_arg		*ft_arg_list_push_back(t_arg *lnk, t_arg *new)
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
