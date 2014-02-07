/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 14:48:58 by rgary             #+#    #+#             */
/*   Updated: 2014/01/23 14:38:21 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

int		check_quote(t_token *tok)
{
	(void)tok;
	return (0);
}

int		check_semicolon(t_token *tok)
{
	(void)tok;
	return (0);
}

int		check_whitespace(t_token *tok)
{
	(void)tok;
	return (0);
}

int		check_stdchar(t_token *tok)
{
	(void)tok;
	return (0);
}

int		check_endofline(t_token *tok)
{
	if (tok->next != NULL)
		return (-1);
	return (0);
}
