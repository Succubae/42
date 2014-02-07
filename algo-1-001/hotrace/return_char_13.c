/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_13.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:26:52 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:51:39 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_backslash(t_ascii *node)
{
	return (&(node->backslash));
}

t_ascii	**ret_cc(t_ascii *node)
{
	return (&(node->cc));
}

t_ascii	**ret_up(t_ascii *node)
{
	return (&(node->up));
}

t_ascii	**ret_under(t_ascii *node)
{
	return (&(node->under));
}

t_ascii	**ret_accent(t_ascii *node)
{
	return (&(node->accent));
}
