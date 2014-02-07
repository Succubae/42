/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:19:10 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:50:14 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_slash(t_ascii *node)
{
	return (&(node->slash));
}

t_ascii	**ret_zero(t_ascii *node)
{
	return (&(node->zero));
}

t_ascii	**ret_one(t_ascii *node)
{
	return (&(node->one));
}

t_ascii	**ret_two(t_ascii *node)
{
	return (&(node->two));
}

t_ascii	**ret_three(t_ascii *node)
{
	return (&(node->three));
}
