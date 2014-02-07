/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_19.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:30:36 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:52:29 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_z(t_ascii *node)
{
	return (&(node->z));
}

t_ascii	**ret_ov(t_ascii *node)
{
	return (&(node->ov));
}

t_ascii	**ret_pipe(t_ascii *node)
{
	return (&(node->pipe));
}

t_ascii	**ret_cv(t_ascii *node)
{
	return (&(node->cv));
}

t_ascii	**ret_tild(t_ascii *node)
{
	return (&(node->tild));
}
