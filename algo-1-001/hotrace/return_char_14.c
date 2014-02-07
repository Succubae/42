/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_14.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:27:28 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:51:49 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_a(t_ascii *node)
{
	return (&(node->a));
}

t_ascii	**ret_b(t_ascii *node)
{
	return (&(node->b));
}

t_ascii	**ret_c(t_ascii *node)
{
	return (&(node->c));
}

t_ascii	**ret_d(t_ascii *node)
{
	return (&(node->d));
}

t_ascii	**ret_e(t_ascii *node)
{
	return (&(node->e));
}
