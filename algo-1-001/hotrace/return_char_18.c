/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_18.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:30:08 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:52:21 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_u(t_ascii *node)
{
	return (&(node->u));
}

t_ascii	**ret_v(t_ascii *node)
{
	return (&(node->v));
}

t_ascii	**ret_w(t_ascii *node)
{
	return (&(node->w));
}

t_ascii	**ret_x(t_ascii *node)
{
	return (&(node->x));
}

t_ascii	**ret_y(t_ascii *node)
{
	return (&(node->y));
}
