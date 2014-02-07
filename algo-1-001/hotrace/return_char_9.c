/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_9.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:23:16 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:50:59 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_H(t_ascii *node)
{
	return (&(node->H));
}

t_ascii	**ret_I(t_ascii *node)
{
	return (&(node->I));
}

t_ascii	**ret_J(t_ascii *node)
{
	return (&(node->J));
}

t_ascii	**ret_K(t_ascii *node)
{
	return (&(node->K));
}

t_ascii	**ret_L(t_ascii *node)
{
	return (&(node->L));
}
