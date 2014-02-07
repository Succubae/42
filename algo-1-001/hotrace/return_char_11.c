/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_11.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:25:12 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:51:23 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_R(t_ascii *node)
{
	return (&(node->R));
}

t_ascii	**ret_S(t_ascii *node)
{
	return (&(node->S));
}

t_ascii	**ret_T(t_ascii *node)
{
	return (&(node->T));
}

t_ascii	**ret_U(t_ascii *node)
{
	return (&(node->U));
}

t_ascii	**ret_V(t_ascii *node)
{
	return (&(node->V));
}
