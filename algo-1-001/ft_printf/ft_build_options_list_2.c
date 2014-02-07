/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_options_list_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 18:17:55 by rgary             #+#    #+#             */
/*   Updated: 2013/12/21 18:51:35 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_printf.h"

t_op	*ft_build_list(t_op *op, char *str, int *i, int j)
{
	int		l;
	t_op	*tmp;
	t_op	*new;

	l = *i;
	tmp = (t_op*)malloc(sizeof(t_op));
	if (!j)
	{
		tmp = ft_build_options_struct(tmp);
		*i = ft_field_options(str, tmp, l);
		new = ft_list_push_back(op, tmp);
		return (new);
	}
	else
		tmp = ft_build_options_struct_spe(tmp);
	new = ft_list_push_back(op, tmp);
	return (new);
}
