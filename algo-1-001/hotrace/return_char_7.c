/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_7.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:21:41 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:50:40 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_right(t_ascii *node)
{
	return (&(node->right));
}

t_ascii	**ret_inter(t_ascii *node)
{
	return (&(node->inter));
}

t_ascii	**ret_arob(t_ascii *node)
{
	return (&(node->arob));
}

t_ascii	**ret_A(t_ascii *node)
{
	return (&(node->A));
}

t_ascii	**ret_B(t_ascii *node)
{
	return (&(node->B));
}
