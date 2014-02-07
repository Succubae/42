/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:24:12 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:51:09 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_M(t_ascii *node)
{
	return (&(node->M));
}

t_ascii	**ret_N(t_ascii *node)
{
	return (&(node->N));
}

t_ascii	**ret_O(t_ascii *node)
{
	return (&(node->O));
}

t_ascii	**ret_P(t_ascii *node)
{
	return (&(node->P));
}

t_ascii	**ret_Q(t_ascii *node)
{
	return (&(node->Q));
}
