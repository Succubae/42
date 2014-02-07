/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:43:47 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:52:07 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_k(t_ascii *node)
{
	return (&(node->k));
}

t_ascii	**ret_l(t_ascii *node)
{
	return (&(node->l));
}

t_ascii	**ret_m(t_ascii *node)
{
	return (&(node->m));
}

t_ascii	**ret_n(t_ascii *node)
{
	return (&(node->n));
}

t_ascii	**ret_o(t_ascii *node)
{
	return (&(node->o));
}
