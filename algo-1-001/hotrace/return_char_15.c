/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_15.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:28:08 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:51:56 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_f(t_ascii *node)
{
	return (&(node->f));
}

t_ascii	**ret_g(t_ascii *node)
{
	return (&(node->g));
}

t_ascii	**ret_h(t_ascii *node)
{
	return (&(node->h));
}

t_ascii	**ret_i(t_ascii *node)
{
	return (&(node->i));
}

t_ascii	**ret_j(t_ascii *node)
{
	return (&(node->j));
}
