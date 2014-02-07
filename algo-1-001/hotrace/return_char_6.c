/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:20:55 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:50:32 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_nine(t_ascii *node)
{
	return (&(node->nine));
}

t_ascii	**ret_dbpoint(t_ascii *node)
{
	return (&(node->dbpoint));
}

t_ascii	**ret_pointcoma(t_ascii *node)
{
	return (&(node->pointcoma));
}

t_ascii	**ret_left(t_ascii *node)
{
	return (&(node->left));
}

t_ascii	**ret_equal(t_ascii *node)
{
	return (&(node->equal));
}
