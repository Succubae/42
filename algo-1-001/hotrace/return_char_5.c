/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:19:48 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 12:50:22 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

t_ascii	**ret_four(t_ascii *node)
{
	return (&(node->four));
}

t_ascii	**ret_five(t_ascii *node)
{
	return (&(node->five));
}

t_ascii	**ret_six(t_ascii *node)
{
	return (&(node->six));
}

t_ascii	**ret_seven(t_ascii *node)
{
	return (&(node->seven));
}

t_ascii	**ret_eight(t_ascii *node)
{
	return (&(node->eight));
}
