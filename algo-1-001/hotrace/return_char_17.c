/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_17.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:29:35 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:52:14 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_p(t_ascii *node)
{
	return (&(node->p));
}

t_ascii	**ret_q(t_ascii *node)
{
	return (&(node->q));
}

t_ascii	**ret_r(t_ascii *node)
{
	return (&(node->r));
}

t_ascii	**ret_s(t_ascii *node)
{
	return (&(node->s));
}

t_ascii	**ret_t(t_ascii *node)
{
	return (&(node->t));
}
