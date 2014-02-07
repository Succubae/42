/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:22:29 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:50:47 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_C(t_ascii *node)
{
	return (&(node->C));
}

t_ascii	**ret_D(t_ascii *node)
{
	return (&(node->D));
}

t_ascii	**ret_E(t_ascii *node)
{
	return (&(node->E));
}

t_ascii	**ret_F(t_ascii *node)
{
	return (&(node->F));
}

t_ascii	**ret_G(t_ascii *node)
{
	return (&(node->G));
}
