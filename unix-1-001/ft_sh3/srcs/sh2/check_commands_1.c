/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 14:22:14 by rgary             #+#    #+#             */
/*   Updated: 2014/01/23 17:02:44 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

int		check_lredir(t_token *tok)
{
	int		prev[5] = {STDCHAR, PIPE, QUOTE, SEMICOLON, -1};
	int		next[3] = {STDCHAR, QUOTE, -1};
	int		i;
	int		j;

	i = j = -1;
	if (tok->prev != NULL)
		i = check_legality(tok->prev, prev);
	if (tok->next != NULL)
		j = check_legality(tok->next, next);
	else
		j = -1;
	if (i == 0)
	{
		if (j == 0)
			return (0);
	}
	else
		parse_error(tok->val);
	return (-1);
}

int		check_rredir(t_token *tok)
{
	int		prev[5] = {SEMICOLON, STDCHAR, QUOTE, PIPE, -1};
	int		next[3] = {STDCHAR, QUOTE, -1};
	int		i;
	int		j;

	i = j = -1;
	if (tok->prev != NULL)
		i = check_legality(tok->prev, prev);
	if (tok->next != NULL)
		j = check_legality(tok->next, next);
	else
		j = -1;
	if (i == 0 && j == 0)
		return (0);
	else
		parse_error(tok->val);
	return (-1);
}

int		check_pipe(t_token *tok)
{
	int		prev[3] = {STDCHAR, QUOTE, -1};
	int		i;
	int		j;

	i = j = -1;
	if (tok->prev != NULL)
		i = check_legality(tok->prev, prev);
	if (tok->next != NULL)
		j = check_legality(tok->next, prev);
	if (i == 0 && j == 0)
		return (0);
	else
		parse_error(tok->val);
	return (-1);
}

int		check_laredir(t_token *tok)
{
	int		prev[3] = {STDCHAR, QUOTE, -1};
	int		i;
	int		j;

	i = j = -1;
	if (tok->prev != NULL)
		i = check_legality(tok->prev, prev);
	if (tok->next != NULL)
		j = check_legality(tok->next, prev);
	if (i == 0 && j == 0)
		return (0);
	else
		parse_error(tok->val);
	return (-1);
}

int		check_raredir(t_token *tok)
{
	int		prev[2] = {STDCHAR, -1};
	int		i;
	int		j;

	i = j = -1;
	if (tok->prev != NULL)
		i = check_legality(tok->prev, prev);
	if (tok->next != NULL)
		j = check_legality(tok->next, prev);
	if (i == 0 && j == 0)
		return (0);
	else
		parse_error(tok->val);
	return (-1);
}

