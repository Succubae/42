/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_12.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:26:00 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:51:30 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_W(t_ascii *node)
{
	return (&(node->W));
}

t_ascii	**ret_X(t_ascii *node)
{
	return (&(node->X));
}

t_ascii	**ret_Y(t_ascii *node)
{
	return (&(node->Y));
}

t_ascii	**ret_Z(t_ascii *node)
{
	return (&(node->Z));
}

t_ascii	**ret_oc(t_ascii *node)
{
	return (&(node->oc));
}
