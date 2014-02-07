/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:16:32 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:49:50 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_space(t_ascii *node)
{
	return (&(node->space));
}

t_ascii	**ret_excl(t_ascii *node)
{
	return (&(node->excl));
}

t_ascii	**ret_quote(t_ascii *node)
{
	return (&(node->quote));
}

t_ascii	**ret_num(t_ascii *node)
{
	return (&(node->num));
}

t_ascii	**ret_dollar(t_ascii *node)
{
	return (&(node->dollar));
}
