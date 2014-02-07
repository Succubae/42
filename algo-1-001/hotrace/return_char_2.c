/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:17:41 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:49:58 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_percent(t_ascii *node)
{
	return (&(node->percent));
}

t_ascii	**ret_and(t_ascii *node)
{
	return (&(node->and));
}

t_ascii	**ret_squote(t_ascii *node)
{
	return (&(node->squote));
}

t_ascii	**ret_op(t_ascii *node)
{
	return (&(node->op));
}

t_ascii	**ret_cp(t_ascii *node)
{
	return (&(node->cp));
}
