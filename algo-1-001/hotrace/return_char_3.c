/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:18:47 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:50:06 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_star(t_ascii *node)
{
	return (&(node->star));
}

t_ascii	**ret_plus(t_ascii *node)
{
	return (&(node->plus));
}

t_ascii	**ret_coma(t_ascii *node)
{
	return (&(node->coma));
}

t_ascii	**ret_minus(t_ascii *node)
{
	return (&(node->minus));
}

t_ascii	**ret_point(t_ascii *node)
{
	return (&(node->point));
}
